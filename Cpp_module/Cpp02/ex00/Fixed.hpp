#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed
{
private:
	int					integer;
	static const int	bits = 8;
public:
	// Default constructor
	Fixed();
	// Default destructor
	~Fixed();
	// Copy constructor
	Fixed(Fixed const &fixed);
	// Equals operator
	Fixed &operator=(Fixed const &fixed);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif