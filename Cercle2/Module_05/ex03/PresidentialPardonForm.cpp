/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:22:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/10 15:39:59 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5) , _target("default_target"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm("PresidentialPardonForm", 25, 5), _target(name) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & f) : AForm(f), _target(f._target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & src){
    if (this != &src){
        AForm::operator=(src);
        this->_target = src._target;}
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    checkExecution(executor);
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}