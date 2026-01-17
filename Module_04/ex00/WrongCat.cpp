/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 14:08:21 by fadzejli          #+#    #+#             */
/*   Updated: 2026/01/17 14:08:42 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal(){
	std::cout << "WrongCat default constructor called." << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(std::string name) : WrongAnimal(), _name(name){
	std::cout << "WrongCat constructor called." << std::endl;
	this->setType("WrongCat");
}

WrongCat::WrongCat(WrongCat const & src) : WrongAnimal(){
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = src;
	this->setType("WrongCat");
}

WrongCat & WrongCat::operator=(WrongCat const &other){
	//std::cout << "Assignation operator called." << std::endl;
	if (this != &other)
		this->_type = other.getType();
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat " << this->_name << " is destroyed" << std::endl;
}