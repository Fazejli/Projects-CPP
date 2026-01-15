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

int ClapTrap::getHitPoints(){
 return (this->_hitPoints);
}

int ClapTrap::getNrjPoints(){
 return (this->_energyPoints);
}

int ClapTrap::getAttackDamage(){
 return (this->_attackDamage);
}

ClapTrap& ClapTrap::operator=(ClapTrap & other){
	std::cout << "Assignment operator called" << std::endl;
	if (this != &other){
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getNrjPoints();
		this->-attackDamage = other.getAttackDamage();
 }
	return (*this);
}

void	ClapTrap::attack(const std::string& name){
	if (this->_hitPoints && this->_energyPoints){
		std::cout << "ClapTrap " << this->_name;
		std::cout << " attacks " << name;
		std::cout << ", causing " << this->_attackDamage;
		std::cout << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " can't attack " << name;
		std:: cout << ". Not enough points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_energyPoints > 0){
			std::cout << this->_name << " has been attacked";
   std::cout << amount << " times. Energy left: ";
		 this->_energyPoints -= amount;
			std::cout << this->_energyPoints << std::endl;
	else if (this->_energyPoints <=0){
   std::cout << this->_name;
			std::cout << " has no nrj points left" << std::endl;}
}

void ClapTrap::beRepaired(unsigned int amount){
	(void) amount;
	std::cout << "takeDamage" << std::endl;
}



/*
std::ostream & operator<<(std::ostream & o, ClapTrap const & i){
	o << i.getName();
	return (o);
}*/