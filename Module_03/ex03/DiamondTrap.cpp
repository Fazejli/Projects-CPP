/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:50 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 10:51:18 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap() , ScavTrap(){
	std::cout << "DiamondTrap default constructor called." << std::endl;
	ClapTrap::_name += "_clap_name";
	this->_name = "default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name){
	std::cout << "DiamondTrap default constructor called." << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	ClapTrap::_name += "_clap_name";
}

DiamondTrap::DiamondTrap(const DiamondTrap& src) : ClapTrap(src), FragTrap(src), ScavTrap(src){
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	*this = src;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap default destructor called." << std::endl;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const & othr){
	//std::cout << "Operator assignation called" << std::endl;
	if (this != &othr)
	{
		ClapTrap::_name += "_clap_name";
		this->_name = othr.getName();
		this->_hitPoints = othr.getHitPoints();
		this->_energyPoints = othr.getNrjPoints();
		this->_attackDamage = othr.getAttackDamage();
	}
	return (*this);
}

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << this->_name << " and My ClapTrap's name is ";
	std::cout << ClapTrap::getName() << std::endl;
}
