#include "ClapTrap.hpp"

/*int	main()
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
}*/

#include "ClapTrap.hpp"

int main()
{
    std::cout << "=== Test 1: Basic Construction ===" << std::endl;
    ClapTrap a("Alice");
    
    std::cout << "\n=== Test 2: Copy Constructor ===" << std::endl;
    ClapTrap b(a);
    
    std::cout << "\n=== Test 3: Default Constructor ===" << std::endl;
    ClapTrap c;
    
    std::cout << "\n=== Test 4: Assignment Operator ===" << std::endl;
    c = a;
    
    std::cout << "\n=== Test 5: Basic Attack ===" << std::endl;
    a.attack("Bob");
    std::cout << "Energy after attack: " << a.getNrjPoints() << std::endl;
    
    std::cout << "\n=== Test 6: Take Damage ===" << std::endl;
    std::cout << "HP before: " << a.getHitPoints() << std::endl;
    a.takeDamage(5);
    std::cout << "HP after: " << a.getHitPoints() << std::endl;
    
    std::cout << "\n=== Test 7: Repair ===" << std::endl;
    std::cout << "HP before: " << a.getHitPoints() << std::endl;
    std::cout << "Energy before: " << a.getNrjPoints() << std::endl;
    a.beRepaired(3);
    std::cout << "HP after: " << a.getHitPoints() << std::endl;
    std::cout << "Energy after: " << a.getNrjPoints() << std::endl;
    
    std::cout << "\n=== Test 8: Energy Depletion ===" << std::endl;
    ClapTrap d("David");
    for (int i = 0; i < 10; i++)
        d.attack("target");
    std::cout << "Energy: " << d.getNrjPoints() << std::endl;
    std::cout << "Trying to attack with 0 energy:" << std::endl;
    d.attack("target");
    std::cout << "Trying to repair with 0 energy:" << std::endl;
    d.beRepaired(5);
    
    std::cout << "\n=== Test 9: Death (0 HP) ===" << std::endl;
    ClapTrap e("Eric");
    std::cout << "HP: " << e.getHitPoints() << std::endl;
    e.takeDamage(10);
    std::cout << "HP: " << e.getHitPoints() << std::endl;
    std::cout << "Trying to attack with 0 HP:" << std::endl;
    e.attack("target");
    
    std::cout << "\n=== Test 10: Destructors ===" << std::endl;
    return 0;
}