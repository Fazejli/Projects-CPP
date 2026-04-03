/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:19:22 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 15:37:34 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice_default"){
}

Ice::Ice(const Ice & src) : AMateria("ice"){
	*this = src;
}

Ice::~Ice(){}

const Ice & Ice::operator=(const Ice & rhs){
	this->_type = rhs.getType();
}

Ice * Ice::clone(const Ice & rhs) const{
	Ice *tmp;
	*tmp = rhs;
	return (tmp);
}

void Ice::use(ICharacter& target){
	std::cout << "* shoots an ice bolt at ";
	std::cout << target.getName() << " *" << std::endl;
}

std::string const & getName() {
	return(this->_type);
}


void equip(AMateria* m);
		void unequip(int idx);