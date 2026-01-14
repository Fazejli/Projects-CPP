#include "Sample.hpp"

int	main()
{
	Sample s1;
	Sample s2(42);
	Sample s3(s1);

	std::cout << "\n" << std::endl;
	std::cout << s1 << std::endl;
	std::cout << s2 << std::endl;
	std::cout << s3 << std::endl;

	std::cout << "\n" << std::endl;
	s3 = s2;
	std::cout << "\n" << std::endl;

	std::cout << s3 << std::endl;

	return (0);
}