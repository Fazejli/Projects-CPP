#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

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
    std::cout << "=== Test 1: Construction Chaining ===" << std::endl;
    ScavTrap s1("Scav1");
    
    std::cout << "\n=== Test 2: Default Constructor ===" << std::endl;
    ScavTrap s2;
    
    std::cout << "\n=== Test 3: Copy Constructor ===" << std::endl;
    ScavTrap s3(s1);
    
    std::cout << "\n=== Test 4: ScavTrap Stats ===" << std::endl;
    std::cout << "Name: " << s1.getName() << std::endl;
    std::cout << "HP: " << s1.getHitPoints() << std::endl;
    std::cout << "Energy: " << s1.getNrjPoints() << std::endl;
    std::cout << "Attack: " << s1.getAttackDamage() << std::endl;
    
    std::cout << "\n=== Test 5: ScavTrap Attack (overridden) ===" << std::endl;
    s1.attack("Enemy");
    
    std::cout << "\n=== Test 6: guardGate ===" << std::endl;
    s1.guardGate();
    
    std::cout << "\n=== Test 7: ClapTrap vs ScavTrap ===" << std::endl;
    ClapTrap c1("Clap1");
    std::cout << "\nClapTrap stats:" << std::endl;
    std::cout << "HP: " << c1.getHitPoints() << " vs ScavTrap HP: " << s1.getHitPoints() << std::endl;
    std::cout << "Energy: " << c1.getNrjPoints() << " vs ScavTrap Energy: " << s1.getNrjPoints() << std::endl;
    std::cout << "Attack: " << c1.getAttackDamage() << " vs ScavTrap Attack: " << s1.getAttackDamage() << std::endl;
    
    std::cout << "\nClapTrap attack:" << std::endl;
    c1.attack("target");
    std::cout << "ScavTrap attack:" << std::endl;
    s1.attack("target");
    
    std::cout << "\n=== Test 8: Polymorphism ===" << std::endl;
    ClapTrap* ptr = &s1;
    ptr->attack("polymorphic target");
    
    std::cout << "\n=== Test 9: Destruction Chaining ===" << std::endl;
    {
        ScavTrap temp("Temporary");
    }
    std::cout << "Temporary ScavTrap destroyed\n" << std::endl;
    
    std::cout << "=== Test 10: All Destructors ===" << std::endl;
    return 0;
}