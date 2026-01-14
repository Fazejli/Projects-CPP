#include "Integer.class.hpp"

Integer::Integer(int const n) : _n(n){
	std::cout << "Constructor called with val " << n << std::endl; 
}

Integer::~Integer(void){
	std::cout << "Destructor called with val " << this->_n << std::endl; 
}

int	Integer::getValue(void) const{
	return (this->_n);
}

Integer &	Integer::operator=( Integer const & rhs)
{
	std::cout << "Assignation called from " << this->_n;
	std::cout << "Operation " << rhs.getValue() << std::endl;
	this->_n = rhs.getValue();
	return *this;
}

Integer 	Integer::operator+( Integer const & rhs) const{
	std::cout << "Operation (+) called with " << this->_n;
	std::cout << " and " << rhs.getValue() << std::endl;
	return Integer( this->_n + rhs.getValue());
}

std::ostream & operator<<(std::ostream & o, Integer const & rhs){
	o << rhs.getValue();
	return (o);
}