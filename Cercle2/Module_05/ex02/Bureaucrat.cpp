/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:37 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 15:18:52 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){}
		
Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name){
	if (src.getGrade() > 150)
		throw GradeTooLowException();
	else if (src.getGrade() < 1)
		throw GradeTooHighException();
	_grade = src._grade;
}
	
Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name){
	if (grade > 150)
		throw GradeTooLowException();
	else if (grade < 1)
		throw GradeTooHighException();
	this->_grade = grade;
}
		
Bureaucrat &Bureaucrat::operator=(const Bureaucrat & src){
	if (this != &src)
	{
		if (src.getGrade() > 150)
			throw GradeTooLowException();
		else if (src.getGrade() < 1)
			throw GradeTooHighException();
		_grade = src._grade;
	}
	return (*this);
}

std::string Bureaucrat::getName(void) const{
	return (this->_name);
}

int Bureaucrat::getGrade(void) const{
	return (this->_grade);
}

//++i
Bureaucrat &Bureaucrat::operator++(void){
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
	return (*this);
}

//i++
Bureaucrat Bureaucrat::operator++(int idx){
	(void)idx;
	Bureaucrat tmp(*this);
	this->_grade--;
	if (this->_grade < 1)
		throw GradeTooHighException();
	return (tmp);
}

//--i
Bureaucrat &Bureaucrat::operator--(void){
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
	return (*this);
}

//i--
Bureaucrat Bureaucrat::operator--(int idx){
	(void)idx;
	Bureaucrat tmp(*this);
	this->_grade++;
	if (this->_grade > 150)
		throw GradeTooLowException();
	return (tmp);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b){
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}

void Bureaucrat::signForm(AForm &f){
	try{
		f.beSigned(*this);
		std::cout << this->getName() << " signed " << f.getName() << std::endl;
	}
	catch (const std::exception & e){
		std::cerr << this->getName() << " couldn't sign " << f.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}

Bureaucrat::~Bureaucrat(){}

void Bureaucrat::executeForm(AForm const &form) const{
	try {
		form.execute(*this);
		std::cout << this->_name << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception & e){
		std::cerr << this->getName() << " couldn't execute " << form.getName();
		std::cerr << " because " << e.what() << std::endl;
	}
}