#include <cmath>

using namespace std;

struct Point
{
    double x;
    double y;

    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}
};

struct Line
{
    //ax + by + c = 0
    double a, b, c;
    //reta com dois pontos
    Point pFirst{}, pSecond{};

    Line() : a(0), b(0), c(0) {}
    Line(Point p1, Point p2)
    {
        a = p1.y - p2.y;
        b = p2.x - p1.x;
        c = p1.x * p2.y - p2.x * p1.y;
        pFirst = p1;
        pSecond = p2;
    }
};

double distaceTwoPoints(Point a, Point b)
{
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double distancePointLine(float x1, float y1, float x2, float y2, float x3, float y3)
{
    auto line = Line(Point(x2, y2), Point(x3, y3));
    return abs(line.a * x1 + line.b * y1 + line.c)/sqrt(line.a * line.a + line.b * line.b);
}

Point intersection(Line l1, Line l2)
{
    double determinant = l1.a * l2.b - l1.b * l2.a;
    if (determinant == 0)
        throw string("Lines are paralel");

    double x = (l2.b*l1.c - l1.b*l2.c)/determinant;
    double y = (l1.a*l2.c - l2.a*l1.c)/determinant;
    return {x, y};
}
