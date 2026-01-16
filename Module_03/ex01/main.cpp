#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//Comment redefinir les attributs de l'enfant sans modifier le .cpp parent?
int	main()
{
	ScavTrap	trapB("Tom");

	//std::cout << trapA << std::endl;
	//std::cout << trapB << std::endl;

	//trapA.attack(trapB.getName());

	trapB.attack(trapB.getName());
	
	return (0);
}