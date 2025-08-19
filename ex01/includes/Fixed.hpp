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
	int   toInt() const;

	// Accès brut (comme en ex00)
	int  getRawBits() const;
	void setRawBits(int const raw);
};

// Surcharge de flux (imprime la représentation float)
std::ostream& operator<<(std::ostream& os, const Fixed& x);

#endif

