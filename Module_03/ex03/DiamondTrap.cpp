/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:50 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 11:46:21 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_crap_name"), FragTrap() , ScavTrap(){
	std::cout << "DiamondTrap default constructor called and " << std::endl;
	this->_name = "default";
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << this->_name << " is created." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_crap_name"), FragTrap(name), ScavTrap(name){
	std::cout << "DiamondTrap assignation constructor called and " << std::endl;
	this->_name = name;
	this->_hitPoints = FragTrap::_hitPoints;
	this->_energyPoints = ScavTrap::_energyPoints;
	this->_attackDamage = FragTrap::_attackDamage;
	std::cout << this->_name << " is created." << std::endl;
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
		this->_name = othr._name;
		this->_hitPoints = othr._hitPoints;
		this->_energyPoints = othr._energyPoints;
		this->_attackDamage = othr._attackDamage;
	}
	return (*this);
}

void DiamondTrap::whoAmI(){
	std::cout << "My name is " << this->_name << " and My ClapTrap's name is ";
	std::cout << ClapTrap::getName() << std::endl;
}
