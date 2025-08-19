#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
	int					_value;
	static const int	_fractionalBits;

public:
	Fixed();							// Constructeur par défaut
	Fixed(const Fixed& other);			// Constructeur de copie
	Fixed& operator=(const Fixed& rhs);	// Opérateur d’affectation
	~Fixed();							// Destructeur

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
