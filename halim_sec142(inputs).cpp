#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void readFromNumberOfLines()
{
    int numberOfLines{};
    cin >> numberOfLines;
    int a{}, b{};
    for (int i = 0; i < numberOfLines; i++)
    {
        cin >> a >> b;
        cout << a+b;
    }
}

void readUntilZeroes()
{
    int a{},b{};
    do
    {
        cin >> a >> b;
        cout << a+b;
    } while (a != 0 && b != 0);
}

void readUntilEOF()
{
    int a{}, b{};
    while (cin >> a >> b)
    {
        if (a == EOF || b == EOF)
            break;
        cout << a+b;
    }
}

void caseNumberBlankLines()
{
    int a{},b{},c{};
    while (cin >> a >> b)
    {
        if (a == EOF || b == EOF)
            break;
        c++;
        cout << "Case " << c << ": " << a+b << endl << endl;
    }
}

void kInputs()
{
    int k{};
    while (cin >> k)
    {
        int ans{}, temp{};
        if (k == EOF)
            return;
        for (int i = 0; i < k; i++)
        {
            cin >> temp;
            ans += temp;
        }
        cout << temp << endl;
    }
}

void kUnknownInputs()
{
    string str{};
    int ans{}, temp{};
    while (getline(cin, str))
    {
        stringstream ss(str);
        while (ss >> temp)
            ans += temp;
        cout << ans << endl;
    }
}
