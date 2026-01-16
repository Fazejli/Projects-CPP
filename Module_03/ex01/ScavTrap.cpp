#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): _name("player_000"){
	std::cout << "Robot default constructor called." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : _name(name){
	std::cout << "Robot constructor called and ";
	std::cout << this->_name << " is created." << std::endl;
}

ScavTrap::~ScavTrap(){
	std::cout << "Robot destructor called." << std::endl;
}

void ScavTrap::guardGate(){
	std::cout << this->_energyPoints << std::endl;
	std::cout << "ScavTrap " << this->getName();
	std::cout << " is now in Gate keeper mode." << std::endl;
}
