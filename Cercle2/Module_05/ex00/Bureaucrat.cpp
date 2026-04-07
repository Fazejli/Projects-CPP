/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:37 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/07 15:30:45 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default"), _grade(150){}
		
Bureaucrat::Bureaucrat(const Bureaucrat & src) : _name(src._name), _grade(src._grade){
	if (src.getGrade() > 150)
		throw GradeTooLowException();
	else if (src.getGrade() < 1)
		throw GradeTooHighException();
	_grade = src._grade;
}

Bureaucrat Bureaucrat::GradeTooHighException(void){
	std::cout << "Invalid grade: Too High (out of range : 1 - 150)" << std::endl;
	this->_grade = 1;
	exit(1);
	return (*this);
}

Bureaucrat Bureaucrat::GradeTooLowException(void){
	std::cout << "Invalid grade: Too Low (out of range : 1 - 150)" << std::endl;
	this->_grade = 150;
	exit(1);
	return (*this);
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
	return (*this);
}

//i++
Bureaucrat Bureaucrat::operator++(int idx){
	(void)idx;
	Bureaucrat tmp(*this);
	this->_grade--;
	return (tmp);
}

//--i
Bureaucrat &Bureaucrat::operator--(void){
	this->_grade++;
	return (*this);
}

//i--
Bureaucrat Bureaucrat::operator--(int idx){
	(void)idx;
	Bureaucrat tmp(*this);
	this->_grade++;
	return (tmp);
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b){
	o << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
	return o;
}

Bureaucrat::~Bureaucrat(){}
