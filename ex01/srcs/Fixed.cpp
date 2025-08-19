#include "Fixed.hpp"
#include <cmath> // roundf

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) {
		this->_value = rhs._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int n) {
	std::cout << "Int constructor called" << std::endl;
	_value = n << _fractionalBits;
}

Fixed::Fixed(float f) {
	std::cout << "Float constructor called" << std::endl;
	_value = static_cast<int>(roundf(f * (1 << _fractionalBits)));
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / static_cast<float>(1 << _fractionalBits);
}

int Fixed::toInt() const {
	return _value >> _fractionalBits;
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << std::endl;
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_value = raw;
}

std::ostream& operator<<(std::ostream& os, const Fixed& x) {
	os << x.toFloat();
	return os;
}

