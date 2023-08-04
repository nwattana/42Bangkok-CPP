#include "Point.hpp"

Fixed findArea(Point const a, Point const b, Point const c)
{
    Fixed area = (a.getX() * (b.getY() - c.getY()) + \
        b.getX() * (c.getY() - a.getY()) + \
        c.getX() * (a.getY() - b.getY()))\
        / 2;
    return (area < 0 ? area * -1 : area);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed area_a = findArea(a, b, point);
    Fixed area_b = findArea(a, c, point);
    Fixed area_c = findArea(b, c, point);


    // Not triangle
    if (a == b || b == c || c == a)
        return false;

    // point == vertice
    if (point == a || point == b || point == c)
        return false;

    // area == 0
    if (area_a == 0 || area_b == 0 || area_c == 0)
        return false;
    
    return (findArea(a, b, c) == area_a + area_b + area_c);
}
