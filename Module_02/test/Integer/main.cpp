#include "Integer.class.hpp"

int	main(){
	Integer	x(30);
	Integer y(10);
	Integer z(0);

	std::cout << "Value of x : " << x << std::endl;
	std::cout << "Value of y : " << y << std::endl;
	std::cout << "\n" << std::endl;

	y = Integer(12);
	std::cout << "Value of y : " << y << std::endl;

	std::cout << "\nValue of z : " << z << std::endl;
	z = x + y;

	std::cout << "\nValue of z : " << z << std::endl;
	std::cout << "\n" << std::endl;
	
	return 0;
}