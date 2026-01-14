#include "Sample.hpp"


Sample::Sample(void) : _foo(0){
	std::cout << "Default onstructor called with val " << this->_foo << std::endl; 
}

Sample::Sample(int const n) : _foo(n){
	std::cout << "Numeric onstructor called with val " << this->_foo << std::endl; 
}

Sample::Sample(Sample const & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src; 
}

Sample::~Sample(void){
	std::cout << "Destructor called" << std::endl; 
}

int	Sample::getFoo(void) const{
	return (this->_foo);
}

Sample &	Sample::operator=( Sample const & rhs)
{
	std::cout << "Assignement operator called.." << std::endl;
	if (this != &rhs)
		this->_foo = rhs.getFoo();
	return *this;
}

std::ostream & operator<<(std::ostream & o, Sample const & i){
	o << "The value of _foo is : " << i.getFoo();
	return (o);
}