#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called and ";
	std::cout << this->_name << " is created." << std::endl;
	setAttackDamage(20);
	setHitPoints(100);
	setNrjPoints(50);
}

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called." << std::endl;
	setAttackDamage(30);
	setHitPoints(100);
	setNrjPoints(100);
}

FragTrap::FragTrap(FragTrap const & src){
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = src;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(){
	std::cout << "High Five?" << std::endl;
}