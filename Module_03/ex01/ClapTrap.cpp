#include "ClapTrap.hpp"

/* PRINT MSG EXAMPLE: */
/*	ClapTrap <name> attacks <target>, causing <damage> points of damage! */

ClapTrap::ClapTrap() : _name("default_player"),
					_hitPoints(10),
					_energyPoints(10),
					_attackDamage(1){
	std::cout << "Default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(1){
	std::cout << "Constructor called and " << this->_name;
	std::cout << " is created." << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "Destructor called." << std::endl;
}

std::string ClapTrap::getName() const{
	return (this->_name);
}

int ClapTrap::getHitPoints() const{
 return (this->_hitPoints);
}

int ClapTrap::getNrjPoints() const {
 return (this->_energyPoints);
}

int ClapTrap::getAttackDamage() const {
 return (this->_attackDamage);
}

ClapTrap& ClapTrap::operator=(ClapTrap const & other){
	std::cout << "Assignment operator called." << std::endl;
	if (this != &other){
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getNrjPoints();
		this->_attackDamage = other.getAttackDamage();
 	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
	//std::cout << this->_name << " is created" << std::endl;
}

void	ClapTrap::attack(const std::string& name){
	if (this->_hitPoints > 0 && this->_energyPoints > 0){
		std::cout << "ClapTrap " << this->_name;
		std::cout << " attacks " << name;
		std::cout << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
		this->_energyPoints--;
	}
	else{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " can't attack " << name;
		std:: cout << ". Not enough points." << std::endl;
	}
}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " has been attacked, losing ";
   		std::cout << amount << " energy points." << std::endl;
		this->_attackDamage += amount;
		this->_energyPoints -= amount;
	}
	else if (this->_energyPoints <= 0)
	{
   		std::cout << "ClapTrap " << this->_name;
		std::cout << " has no energy points left" << std::endl;
	}
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name;
		std::cout << " has been repaired, gaining ";
   		std::cout << amount << " hitpoint." << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	if (this->_energyPoints <= 0)
	{
   		std::cout << "ClapTrap " << this->_name;
		std::cout << " has no energy points left" << std::endl;
	}
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & i){
	o << i.getNrjPoints();
	return (o);
}