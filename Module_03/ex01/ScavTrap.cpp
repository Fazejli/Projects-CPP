#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "Robot constructor called and ";
	std::cout << this->_name << " is created." << std::endl;
}

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "Robot default constructor called and ";
	std::cout << this->_name << " is created." << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const & src){
	std::cout << "Robot copy constructor called." << std::endl;
	*this = src;
}

ScavTrap & ScavTrap::operator=(ScavTrap const & other){
	std::cout << "Robot assignment operator called." << std::endl;
	if (this != &other){
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getNrjPoints();
		this->_attackDamage = other.getAttackDamage();
 	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << "Robot destructor called." << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap " << this->getName();
	std::cout << " is now in Gate keeper mode." << std::endl;
}

void ScavTrap::attack(const std::string& target){
	std::cout << "ScavTrap " << this->_name;
	std::cout << " attacks " << target;
	std::cout << "\n" << std::endl;
}

/*std::ostream & operator<<(std::ostream & o, ScavTrap const & i){
	o << i.getNrjPoints();
	return (o);
}*/