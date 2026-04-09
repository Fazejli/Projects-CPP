/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:15:34 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 15:43:05 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("default", 145, 137) , _target("default_target"){}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm("default", 145, 137), _target(name) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm & f) : AForm(f), _target(f._target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm & src){
    if (this != &src){
    AForm::operator=(src);
    this->_target = src._target;}
    return (*this);
}

std::string ShrubberyCreationForm::getTarget(void) const{
    return (this->_target);
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (executor.getGrade() <= this->getExecGrade() && this->getSignStatus() == true)
    {
        std::ofstream f(this->getTarget() + "_shrubbery");
        f << "file created, writes ASCII trees inside it" << std::endl;
        return ;
    }
    throw
        GradeTooLowException();
}
