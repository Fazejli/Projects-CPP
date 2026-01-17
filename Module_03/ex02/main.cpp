#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
# include "FragTrap.hpp"

/*
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
}*/

int main()
{
    std::cout << "=== Test 1: FragTrap Construction Chaining ===" << std::endl;
    FragTrap f1("Frag1");
    
    std::cout << "\n=== Test 2: FragTrap Default Constructor ===" << std::endl;
    FragTrap f2;
    
    std::cout << "\n=== Test 3: FragTrap Copy Constructor ===" << std::endl;
    FragTrap f3(f1);
    
    std::cout << "\n=== Test 4: FragTrap Stats ===" << std::endl;
    std::cout << "Name: " << f1.getName() << std::endl;
    std::cout << "HP: " << f1.getHitPoints() << std::endl;
    std::cout << "Energy: " << f1.getNrjPoints() << std::endl;
    std::cout << "Attack: " << f1.getAttackDamage() << std::endl;
    
    std::cout << "\n=== Test 5: highFivesGuys ===" << std::endl;
    f1.highFivesGuys();
    
    std::cout << "\n=== Test 6: FragTrap Attack (inherited from ClapTrap) ===" << std::endl;
    f1.attack("Enemy");
    
    std::cout << "\n=== Test 7: All Three Classes ===" << std::endl;
    ClapTrap c("Clap");
    ScavTrap s("Scav");
    FragTrap f("Frag");
    
    std::cout << "\nStats comparison:" << std::endl;
    std::cout << "ClapTrap - HP: " << c.getHitPoints() << ", Energy: " << c.getNrjPoints() << ", Attack: " << c.getAttackDamage() << std::endl;
    std::cout << "ScavTrap - HP: " << s.getHitPoints() << ", Energy: " << s.getNrjPoints() << ", Attack: " << s.getAttackDamage() << std::endl;
    std::cout << "FragTrap - HP: " << f.getHitPoints() << ", Energy: " << f.getNrjPoints() << ", Attack: " << f.getAttackDamage() << std::endl;
    
    std::cout << "\nAttacks:" << std::endl;
    c.attack("target");
    s.attack("target");
    f.attack("target");
    
    std::cout << "\nSpecial abilities:" << std::endl;
    s.guardGate();
    f.highFivesGuys();
    
    std::cout << "\n=== Test 8: FragTrap Destruction Chaining ===" << std::endl;
    {
        FragTrap temp("Temporary");
    }
    std::cout << "Temporary FragTrap destroyed\n" << std::endl;
    
    std::cout << "=== Test 9: Polymorphism with FragTrap ===" << std::endl;
    ClapTrap* ptr = &f1;
    ptr->attack("polymorphic target");
    
    std::cout << "\n=== Test 10: All Destructors ===" << std::endl;
    return 0;
}