#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
    private:
        // implement Vertor in direction x
        Fixed _x;
        Fixed _y;

    public:
        Point(void);
        Point(int const x, int const y);
        Point(float const x, float const y);
        Point(Fixed const x, Fixed const y);
        Point(Point const &src);
        ~Point(void);

        Point &operator=(Point const &rhs);

        // overload comparison operator
        bool operator==(const Point &rhs) const;


        Fixed getX(void) const;
        Fixed getY(void) const;
};

std::ostream &operator<<(std::ostream &o, Point const &rhs);

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif