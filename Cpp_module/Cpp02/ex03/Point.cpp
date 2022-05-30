#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(float const a, const float b) : x(a), y(b) {}

Point::Point(Point const &point) : x(point.getX()), y(point.getY()) {
}

Point &Point::operator=(Point &point) {
    return (point);
}

Fixed Point::getX() const {
    return (x);
}

Fixed Point::getY() const {
    return (y);
}

Point::~Point() {}