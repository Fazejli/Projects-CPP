#include "ClapTrap.hpp"

/* PRINT MSG EXAMPLE: */
/*	ClapTrap <name> attacks <target>, causing <damage> points of damage! */

ClapTrap::ClapTrap() : _name("default_player"),
						_hitPoints(10),
						_energyPoints(10),
						_attackDamage(1){
	std::cout << "ClapTrap default constructor called." << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(1){
	std::cout << "ClapTrap constructor called and " << this->_name;
	std::cout << " is created." << std::endl;
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called." << std::endl;
}
// Getters //
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

// setters //

void ClapTrap::setHitPoints(int hp) {
	this->_hitPoints = hp;
}

void ClapTrap::setNrjPoints(int energy)  {
	this->_energyPoints = energy;
}

void ClapTrap::setAttackDamage(int damage)  {
	this->_attackDamage = damage;
}

/////

ClapTrap& ClapTrap::operator=(ClapTrap const & other){
	//std::cout << "Assignment operator called." << std::endl;
	if (this != &other){
		this->_name = other.getName();
		this->_hitPoints = other.getHitPoints();
		this->_energyPoints = other.getNrjPoints();
		this->_attackDamage = other.getAttackDamage();
 	}
	return (*this);
}

ClapTrap::ClapTrap(ClapTrap const & src) {
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = src;
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
		std:: cout << ". Not enough energy points." << std::endl;
	}
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
}

void ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap " << this->_name << " has been attacked,";
	std::cout << " losing " << amount << " points." << std::endl;
	this->_hitPoints -= amount;
}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoints > 0)
	{
		std::cout << "ClapTrap " << this->_name << " has been repaired,";
		std::cout << " gaining " << amount << " hitpoints." << std::endl;
		this->_hitPoints += amount;
		this->_energyPoints--;
	}
	else if (this->_energyPoints <= 0)
	{
   		std::cout << "ClapTrap " << this->_name;
		std::cout << " has no energy points left." << std::endl;
	}
	if (this->_energyPoints < 0)
		this->_energyPoints = 0;
}

std::ostream & operator<<(std::ostream & o, ClapTrap const & i){
	o << i.getNrjPoints();
	return (o);
}