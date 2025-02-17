#include <cmath>
#include <iostream>

using namespace std;

struct Point
{
    double x;
    double y;

    Point() : x(0), y(0) {}
    Point(double x, double y) : x(x), y(y) {}

    double distanceToAnotherPoint(Point p)
    {
        return sqrt(pow(x - p.x, 2) + pow(y - p.y, 2));
    }
};

struct Line
{
    //ax + by + c = 0
    double a, b, c;
    //Linha definida por dois pontos
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
    double slope()
    {
        return (pSecond.y - pFirst.y)/(pSecond.x - pFirst.x);
    }
    double distanceToPoint(Point p)
    {
        return abs(a * p.x + b * p.y + c)/sqrt(pow(a, 2) + pow(b, 2));
    }
    double angleBetweenLines(Line l)
    {
        double tang = abs((this->slope() - l.slope())/(1 + this->slope() * l.slope()));
        return pow(tan(tang), -1);
    }
    Point intersectPoint(Line l)
    {
        double determinant = a * l.b - b * l.a;
        if (determinant == 0)
            throw string("Lines are parallel");

        double x = (l.b*c - b*l.c)/determinant;
        double y = (a*l.c - l.a*c)/determinant;
        return {x, y};
    }
};

struct Circle
{
    Point center;
    double radius;

    Circle() : center(Point(0,0)), radius(0) {}

    double area()
    {
        return M_PI * pow(radius, 2);
    }

    double circumference()
    {
        return 2 * M_PI * radius;
    }

    double areaOfASector(double alpha)
    {
        return pow(radius, 2) * alpha/2;
    }
    double areaOfASegment(Point p1, Point p2)
    {
        Line segment1 = Line(center, p1);
        Line segment2 = Line(center, p2);
        double alpha = segment1.angleBetweenLines(segment2);

        return areaOfASector(alpha) - (pow(radius, 2) * sin(alpha))/2;
    }
};

