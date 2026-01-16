#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("A");
	ClapTrap const b("C");
	ClapTrap c(b);

	std::cout << "nrj a:" <<  a << std::endl;
	a.attack(c.getName());
	std::cout << "nrj a:" <<  a << std::endl;
	c.takeDamage(2);
	std::cout << "nrj c:" <<  c << std::endl;
	c.beRepaired(1);
	std::cout << "nrj c:" <<  c << std::endl;
	c.attack(a.getName());
	std::cout << "nrj c:" <<  c << std::endl;
	std::cout << "nrj a:" <<  a << std::endl;
	a.takeDamage(2);
	std::cout << "nrj a:" <<  a << std::endl;

	c.attack(a.getName());
	std::cout << "nrj c:" <<  c << std::endl;
	std::cout << "nrj a:" <<  a << std::endl;
	a.takeDamage(2);
	std::cout << "nrj a:" <<  a << std::endl;

	c.attack(a.getName());
	std::cout << "nrj c:" <<  c << std::endl;
	std::cout << "nrj a:" <<  a << std::endl;
	a.takeDamage(2);
	std::cout << "nrj a:" <<  a << std::endl;

	c.attack(a.getName());
	std::cout << "nrj c:" <<  c << std::endl;
	std::cout << "nrj a:" <<  a << std::endl;
	a.takeDamage(2);
	std::cout << "nrj a:" <<  a << std::endl;

	c.beRepaired(10);
	std::cout << "nrj c:" <<  c << std::endl;
	return (0);
}