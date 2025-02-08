#include <iostream>
#include <set>

#define point pair<float,float>
using namespace std;

//variavel global para armazenar os pontos da envoltoria
set<point > hull;

//produto vetorial
float crossProduct(point a, point b, point p)
{
    return (p.second - a.second) * (b.first - a.first) - (b.second - a.second) * (p.first - a.first);
}

//usa produto vetorial para determianar de que lado p em relacao a reta ab
int wichSide(point a, point b, point p)
{
    float v = crossProduct(a, b, p);
    if (v > 0)
        return 1;
    else if (v < 0)
        return -1;
    else
        return 0;
}

void quickhullAux(point S[], int n, point a, point b, int side)
{
    int index = -1;
    int maxDist = 0;

    for (int i = 0; i < n; i++)
    {
        int temp = abs(crossProduct(a, b, S[i]));
        if (wichSide(a, b, S[i]) == side && temp > maxDist)
        {
            index = i;
            maxDist = temp;
        }
    }
    if (index == -1)
    {
        hull.insert(a);
        hull.insert(b);
        return;
    }

    quickhullAux(S, n, S[index], a, -wichSide(S[index], a, b));
    quickhullAux(S, n, S[index], b, -wichSide(S[index], b, a));
}

void quickhull(point S[], int n)
{
    int minXi = 0;
    int maxXi = 0;
    for (int i = 0; i < n; i++)
    {
        if (S[i].first >= S[maxXi].first)
        {
            maxXi = i;
        }
        else
            break;
    }

    quickhullAux(S, n, S[minXi], S[maxXi], 1);
    quickhullAux(S, n, S[minXi], S[maxXi], -1);
}
