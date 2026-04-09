/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:15:34 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 14:51:46 by fadzejli         ###   ########.fr       */
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

void ShrubberyCreationForm::execute(Bureaucrat const & executor){
    if (executor.getGrade() <= this->getExecGrade() && this->getSignStatus() == true)
    {
        std::cout << "Creates a file <target>_shrubbery in the working directory and writes ASCII trees inside it." << std::endl;
        return ;
    }
    throw
        GradeTooLowException();
}
