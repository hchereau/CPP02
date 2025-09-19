#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << "\n";
}

Fixed::Fixed(const Fixed& other) : _value(other._value) { // la construction par initialisation ne marche que deans les constructeurs
	std::cout << "Copy constructor called" << "\n";
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << "\n";
	if (this != &rhs)
		this->_value = rhs._value;
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << "\n";
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << "\n";
	return this->_value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << "\n";
	this->_value = raw;
}

