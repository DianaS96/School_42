#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed
{
private:
	int					integer;
	static const int	bits = 8;
public:
	// Default constructor
	Fixed();
	// Constructor that takes a constant integer as a parameter
	Fixed(const int a);
	// Constructor that takes a constant floating-point number as a parameter
	Fixed(const float a);
	// Default destructor
	~Fixed();
	// Copy constructor
	Fixed(Fixed const &fixed);
	// Equals operator
	Fixed &operator=(Fixed const &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	int toInt(void) const;
	float toFloat(void) const;
};

// overload of the insertion («) operator
std::ostream &operator<<(std::ostream &object, Fixed const &fixed);
#endif