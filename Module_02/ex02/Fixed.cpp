#include "Fixed.hpp"

Fixed::Fixed(void) : _value(0){
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src) {
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::Fixed(int const intNbr) {
	//std::cout << "Integer constructor called" << std::endl;
	this->_value = intNbr << _nbBits;
}

Fixed::Fixed(float const floatNbr) : _value(floatNbr){
	//std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(floatNbr * (1 << _nbBits));
}

float Fixed::toFloat(void) const{
	return float(this->_value) / float(1 << _nbBits);
}

int	Fixed::toInt(void) const{
	return this->_value >> _nbBits;
}

Fixed::~Fixed(void){
}

Fixed & Fixed::operator=( Fixed const & rhs){
	//std::cout << "Assignment operator called" << std::endl;
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

Fixed & Fixed::operator+( Fixed const & rhs){
	//std::cout << "Addition operator called" << std::endl;
	this->_value += rhs.getRawBits();
	return (*this);
}

Fixed & Fixed::operator-( Fixed const & rhs){
	//std::cout << "Soustraction operator called" << std::endl;
	this->_value -= rhs.getRawBits();
	return (*this);
}

Fixed & Fixed::operator*( Fixed const & rhs){
	//std::cout << "Copy assignment operator called" << std::endl;
	this->_value = this->_value * rhs.getRawBits();
	return (*this);
}

Fixed & Fixed::operator/( Fixed const & rhs){
	//std::cout << "Copy assignment operator called" << std::endl;
	if (rhs.getRawBits() != 0)
		this->_value /= rhs.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const{
	return this->_value;
}

void Fixed::setRawBits(int const raw){
	this->_value = raw;
}

std::ostream & operator<<(std::ostream & o, Fixed const & i){
	o << i.toFloat();
	return (o);
}

