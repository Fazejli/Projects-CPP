#include "ClapTrap.hpp"

/* PRINT MSG EXAMPLE: */
/*	ClapTrap <name> attacks <target>, causing <damage> points of damage! */

ClapTrap::ClapTrap() : _name("Default_player"),
					_hitPoints(10),
					_energyPoints(10),
					_attackDamage(0){
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0){
	std::cout << "Constructor called and " << this->_name;
	std::cout << " is created" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap & src){
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	std::cout << this->_name << " is created" << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called" << std::endl;
}

std::string ClapTrap::getName(){
	return (this->_name);
}

ClapTrap& ClapTrap::operator=(ClapTrap & other){
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other)
		this->_name = other.getName();
	return (*this);
}

/*
std::ostream & operator<<(std::ostream & o, ClapTrap const & i){
	o << i.getName();
	return (o);
}*/