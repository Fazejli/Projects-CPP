#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap constructor called and ";
	std::cout << this->_name << " is created." << std::endl;
	setAttackDamage(30);
	setHitPoints(100);
	setNrjPoints(100);
}

FragTrap::FragTrap() : ClapTrap() {
	std::cout << "FragTrap default constructor called." << std::endl;
	setAttackDamage(30);
	setHitPoints(100);
	setNrjPoints(100);
}

FragTrap::FragTrap(FragTrap const & src) : ClapTrap(src){
	std::cout << "FragTrap copy constructor called." << std::endl;
	*this = src;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap " << this->_name << " is destroyed." << std::endl;
}

FragTrap & FragTrap::operator=(FragTrap const & other){
	//std::cout << "FragTrap assignment operator called." << std::endl;
	if (this != &other){
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getNrjPoints();
		this->_attackDamage = other.getAttackDamage();
 	}
	return (*this);
}

void FragTrap::highFivesGuys(){
	std::cout << "Give me five!" << std::endl;
}