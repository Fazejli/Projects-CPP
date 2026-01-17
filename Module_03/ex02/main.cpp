#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
# include "FragTrap.hpp"

//Comment redefinir les attributs de l'enfant sans modifier le .cpp parent?
int	main()
{
	ClapTrap	trapA("Bob");
	ScavTrap	trapB("Tom");

	std::cout << "\n" << trapA.getName() << trapA << "			" << trapB.getName() << trapB << "\n" << std::endl;
	//std::cout << trapB.getAttackDamage() << std::endl;
	trapA.attack(trapB.getName());
	trapB.takeDamage(2);
	
	std::cout << "\n" << trapA.getName() << trapA << "			" << trapB.getName() << trapB << "\n" << std::endl;

	trapB.beRepaired(2);
	std::cout << "\n" << trapA.getName() << trapA << "			" << trapB.getName() << trapB.getHitPoints() << "\n" << std::endl;
	
	return (0);
}