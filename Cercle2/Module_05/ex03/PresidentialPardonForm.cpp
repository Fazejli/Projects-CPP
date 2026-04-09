/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:22:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 15:13:47 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("default", 25, 5) , _target("default_target"){}

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm("default", 25, 5), _target(name) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm & f) : AForm(f), _target(f._target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm & src){
    if (this != &src){
    AForm::operator=(src);
    this->_target = src._target;}
    return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() <= this->getExecGrade() && this->getSignStatus() == true){
        std::cout << this->_target << " has been pardoned bu Zaphod Beeblebrox" << std::endl;
        return ;
    }
    throw
        GradeTooLowException();
}