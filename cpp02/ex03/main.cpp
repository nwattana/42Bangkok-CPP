#include "Point.hpp"

void    check(Point const a, Point const b, Point const c, Point const point)
{
    std::cout << point << (bsp(a, b, c, point) ? " IN ": " NOT IN ") << a << "," << b << "," << c << std::endl;
}


int main(void)
{
    Point a(0, 0);
    Point b(0, 5);
    Point c(5, 0);

    // random point
    std::cout << "==== random point =====" << std::endl;
    check(a, b, c, Point(1, 1));
    check(a, b, c, Point(2, 2));
    check(a, b, c, Point(3, 3));
    check(a, b, c, Point(4, 4));
    
    // edge
    std::cout << "====== edge =======" << std::endl;
    check(a, b, c, Point(0, 2));
    check(a, b, c, Point(0, 1));
    check(a, b, c, Point(4, 0));
    check(a, b, c, Point(3, 0));


    // vertice
    std::cout << "====== vertice =======" << std::endl;
    check(a, b, c, a);
    check(a, b, c, b);
    check(a, b, c, c);

    // not triangle
    std::cout << "==== not triangle =====" << std::endl;
    Point d(0, 0);
    check(a, b, d, Point(1, 1));
    check(a, b, d, Point(2, 2));
    check(a, b, d, Point(3, 3));
    check(a, b, d, Point(4, 4));


    return 0;
}