/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 14:46:31 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 15:07:18 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("default"){}

AMateria::AMateria(std::string const & type){
	this->_type = type;
}

AMateria::AMateria(const AMateria & src){
	*this = src;
}

AMateria::~AMateria(){}

const AMateria & AMateria::operator=(const AMateria& rhs){
	this->_type = rhs._type;
}

std::string const & AMateria::getType() const{
	return (this->_type);
}

void AMateria::use(ICharacter& target){
	std::cout << "* holds " << this->_type << " before ";
	std::cout << target.getName() << " *" << std::endl;
}