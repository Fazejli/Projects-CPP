/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 14:22:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 14:51:40 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("default", 72, 45) , _target("default_target"){}

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm("default", 72, 45), _target(name) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm & f) : AForm(f), _target(f._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm & src){
    if (this != &src){
    AForm::operator=(src);
    this->_target = src._target;}
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor){
    if (executor.getGrade() <= this->getExecGrade() && this->getSignStatus() == true){
        std::cout << "** drilling noise **" << std::endl;
        std::cout << this->_target << " has been robotomized successfully 50% of the time." << std::endl;
        return ;
    }
    throw
        GradeTooLowException();
}
