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
    // Not triangle
    if (a == b || b == c || c == a)
        return false;

    // point == vertice
    if (point == a || point == b || point == c)
        return false;
    return (findArea(a, b, c) == \
        findArea(a, b, point) + \
        findArea(a, c, point) + \
        findArea(b, c, point));
}
