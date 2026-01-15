#include "ClapTrap.hpp"

int	main()
{
	ClapTrap a("toto");
	ClapTrap b("bob");
	ClapTrap c(b);

	a.attack("bob");
	return (0);
}