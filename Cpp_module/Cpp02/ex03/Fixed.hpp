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

	bool operator>(const Fixed &fixed) const;
	bool operator<(const Fixed &fixed) const;
	bool operator>=(const Fixed &fixed) const;
	bool operator<=(const Fixed &fixed) const;
	bool operator==(const Fixed &fixed) const;
	bool operator!=(const Fixed &fixed) const;

	Fixed	operator+(const Fixed &fixed) const;
	Fixed	operator-(const Fixed &fixed) const;
	Fixed	operator*(const Fixed &fixed) const;
	Fixed	operator/(const Fixed &fixed) const;

	// prefix
	Fixed	&operator++(void);
	Fixed	&operator--(void);
	
	// postfix
	Fixed	operator++(int);
	Fixed	operator--(int);

	static Fixed& min(Fixed &a, Fixed &b);
	static const Fixed& min(const Fixed &a, const Fixed &b);
	static Fixed& max(Fixed &a, Fixed &b);
	static const Fixed& max(const Fixed &a, const Fixed &b);

};

// overload of the insertion («) operator
std::ostream &operator<<(std::ostream &object, Fixed const &fixed);

#endif