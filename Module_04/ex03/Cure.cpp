/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 15:07:31 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 15:18:59 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure_default"){
}

Cure::Cure(const Cure & src) : AMateria("cure"){
	*this = src;
}

Cure::~Cure(){}

const Cure & Cure::operator=(const Cure & rhs){
	this->_type = rhs.getType();
}

Cure * Cure::clone(const Cure & rhs) const{
	Cure *tmp;
	*tmp = rhs;
	return (tmp);
}

void Cure::use(ICharacter& target){
	std::cout << "* heals ";
	std::cout << target.getName() << "'s wounds *" << std::endl;
}