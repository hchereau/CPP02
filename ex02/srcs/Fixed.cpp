#include "Fixed.hpp"
#include <cmath>

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs) _value = rhs._value;
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

// -------- Comparaisons --------
bool Fixed::operator>(const Fixed& rhs)  const { return _value >  rhs._value; }
bool Fixed::operator<(const Fixed& rhs)  const { return _value <  rhs._value; }
bool Fixed::operator>=(const Fixed& rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed& rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed& rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed& rhs) const { return _value != rhs._value; }

// -------- Arithmétique --------
// Implémentation simple & lisible : passer par float puis reconstruire un Fixed
Fixed Fixed::operator+(const Fixed& rhs) const { return Fixed(this->toFloat() + rhs.toFloat()); }
Fixed Fixed::operator-(const Fixed& rhs) const { return Fixed(this->toFloat() - rhs.toFloat()); }
Fixed Fixed::operator*(const Fixed& rhs) const { return Fixed(this->toFloat() * rhs.toFloat()); }
Fixed Fixed::operator/(const Fixed& rhs) const { return Fixed(this->toFloat() / rhs.toFloat()); }
// NB: le sujet tolère un crash si division par 0, donc pas d’obligation de guard:contentReference[oaicite:2]{index=2}.

// -------- Incr/Decr --------
// Un pas = 1 LSB = 1/(1<<8) -> on manipule le brut.
Fixed& Fixed::operator++()	{ ++_value; return *this; }	  // pré-incr
Fixed& Fixed::operator--()	{ --_value; return *this; }	  // pré-decr
Fixed  Fixed::operator++(int) { Fixed tmp(*this); ++_value; return tmp; } // post-incr
Fixed  Fixed::operator--(int) { Fixed tmp(*this); --_value; return tmp; } // post-decr

// -------- min/max --------
Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}
const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}
Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}
const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

// -------- Flux --------
std::ostream& operator<<(std::ostream& os, const Fixed& x) {
	os << x.toFloat();
	return os;
}
