#include "Point.hpp"
// https://stackoverflow.com/questions/2049582/how-to-determine-if-a-point-is-in-a-2d-triangle
Fixed area(Point const a, Point const b, Point const c)
{
   

    Fixed one(a.getX() * (b.getY() - c.getY()));
    Fixed two(b.getX() * (c.getY() - a.getY()));
    Fixed three(c.getX() * (a.getY() - b.getY()));
    Fixed check(one.toFloat() + two.toFloat() + three.toFloat());
    if (check < 0)
        check = check * (-1);
    return (check);
}

bool bsp( Point const a, Point const b, Point const c, Point const point) {    
    Fixed total_area = area(a, b, c);
    Fixed area1 = area(a, b, point);
    Fixed area2 = area(a, c, point);
    Fixed area3 = area(b, c, point);
    if (total_area.getRawBits() == 0)
    {
        std::cout << "There is no triangle. You should pass 3 different points as a, b, c args" << std::endl;
        return (false);

    }
    if (area1.getRawBits() == 0 || area2.getRawBits() == 0 || area3.getRawBits() == 0)
        std::cout << "Point is on one of the vertices" << std::endl;
    // std::cout << total_area.getRawBits() << std::endl;
    // std::cout << area1.getRawBits() << std::endl;
    // std::cout << area2.getRawBits() << std::endl;
    // std::cout << area3.getRawBits() << std::endl;
    return (total_area.getRawBits() == area1.getRawBits() + area2.getRawBits() + area3.getRawBits());
}