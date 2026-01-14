#include "Fixed.hpp"


int main( void ) {
	Fixed a(5);
	Fixed const b(1);
	//a = a + b;
	std::cout << a << std::endl;
	std::cout << a + 2 << std::endl;
	std::cout << a - b << std::endl;
	std::cout << "a = " << a << "b = " << b << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a / b << std::endl;
	std::cout << b << std::endl;
	//std::cout << Fixed::max( a, b ) << std::endl;
	return 0;

}

/*	Output	*/
/*
*/