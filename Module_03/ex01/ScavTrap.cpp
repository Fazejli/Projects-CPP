#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called and ";
	std::cout << this->_name << " is created." << std::endl;
	setAttackDamage(20);
	setHitPoints(100);
	setNrjPoints(50);
}

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called." << std::endl;
	setAttackDamage(20);
	setHitPoints(100);
	setNrjPoints(50);
}

ScavTrap::ScavTrap(ScavTrap const & src) : ClapTrap(src){
	std::cout << "ScavTrap copy constructor called." << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other){
	//std::cout << "ScavTrap assignment operator called." << std::endl;
	if (this != &other){
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getNrjPoints();
		this->_attackDamage = other.getAttackDamage();
 	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap " << this->_name << " is destroyed." << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName();
	std::cout << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target){
	std::cout << "ScavTrap " << this->getName();
	std::cout << " attacks " << target ;
	std::cout << " causing " << this->getAttackDamage();
	std::cout << " points of damage." << std::endl;
}

std::ostream & operator<<(std::ostream & o, ScavTrap const & i){
	o << i.getNrjPoints();
	return (o);
}