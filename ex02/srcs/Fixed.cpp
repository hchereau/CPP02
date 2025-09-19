#include "Fixed.hpp"

const int Fixed::_fractionalBits = 8;

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << '\n';
}

Fixed::Fixed(const Fixed& other) : _value(other._value) {
	std::cout << "Copy constructor called" << '\n';
}

Fixed& Fixed::operator=(const Fixed& rhs) {
	std::cout << "Copy assignment operator called" << '\n';
	if (this != &rhs) {
		this->_value = rhs._value;
	}
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int n) : _value(n << _fractionalBits) {
	std::cout << "Int constructor called" << '\n';
}

Fixed::Fixed(float f) : _value(static_cast<int>(roundf(f * (scale())))) {
	std::cout << "Float constructor called" << '\n';
}

float Fixed::toFloat() const {
	return static_cast<float>(_value) / static_cast<float>(scale());
}

int Fixed::toInt() const {
	return static_cast<int>(toFloat());
}

int Fixed::getRawBits() const {
	std::cout << "getRawBits member function called" << '\n';
	return _value;
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << '\n';
	_value = raw;
}

int Fixed::scale(){
	return 1 << _fractionalBits;
}

// -------- Comparaisons --------
bool Fixed::operator>(const Fixed& rhs)  const { return _value >  rhs._value; }
bool Fixed::operator<(const Fixed& rhs)  const { return _value <  rhs._value; }
bool Fixed::operator>=(const Fixed& rhs) const { return _value >= rhs._value; }
bool Fixed::operator<=(const Fixed& rhs) const { return _value <= rhs._value; }
bool Fixed::operator==(const Fixed& rhs) const { return _value == rhs._value; }
bool Fixed::operator!=(const Fixed& rhs) const { return _value != rhs._value; }

// -------- Arithmétique --------
Fixed Fixed::operator+(const Fixed& rhs) const { return Fixed(this->toFloat() + rhs.toFloat()); }
Fixed Fixed::operator-(const Fixed& rhs) const { return Fixed(this->toFloat() - rhs.toFloat()); }
Fixed Fixed::operator*(const Fixed& rhs) const { return Fixed(this->toFloat() * rhs.toFloat()); }
Fixed Fixed::operator/(const Fixed& rhs) const { return Fixed(this->toFloat() / rhs.toFloat()); }
// le sujet tolère un crash si division par 0, donc pas d’obligation de guard:contentReference[oaicite:2]{index=2}.

// -------- Incr/Decr --------
Fixed& Fixed::operator++()	{ ++_value; return *this; }
Fixed& Fixed::operator--()	{ --_value; return *this; }
Fixed  Fixed::operator++(int) { Fixed tmp(*this); ++_value; return tmp; }
Fixed  Fixed::operator--(int) { Fixed tmp(*this); --_value; return tmp; }

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
