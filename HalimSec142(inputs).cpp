#include <iostream>

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
