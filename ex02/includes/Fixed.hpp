#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int				 _value;
	static const int	_fractionalBits;

public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& rhs);
	~Fixed();

	explicit Fixed(int n);
	explicit Fixed(float f);

	float toFloat() const;
	int   toInt()   const;

	int  getRawBits() const;
	void setRawBits(int const raw);

	// --- Comparaisons ---
	bool operator>(const Fixed& rhs)  const;
	bool operator<(const Fixed& rhs)  const;
	bool operator>=(const Fixed& rhs) const;
	bool operator<=(const Fixed& rhs) const;
	bool operator==(const Fixed& rhs) const;
	bool operator!=(const Fixed& rhs) const;

	// --- Arithmétique ---
	Fixed operator+(const Fixed& rhs) const;
	Fixed operator-(const Fixed& rhs) const;
	Fixed operator*(const Fixed& rhs) const;
	Fixed operator/(const Fixed& rhs) const;

	Fixed& operator++();
	Fixed& operator--();

	Fixed operator++(int);
	Fixed operator--(int);

	// --- min/max ---
	static Fixed&		min(Fixed& a, Fixed& b);
	static const Fixed&	min(const Fixed& a, const Fixed& b);
	static Fixed&		max(Fixed& a, Fixed& b);
	static const Fixed&	max(const Fixed& a, const Fixed& b);
};

// Surcharge de flux (affiche la représentation float)
std::ostream&	operator<<(std::ostream& os, const Fixed& x);

#endif
