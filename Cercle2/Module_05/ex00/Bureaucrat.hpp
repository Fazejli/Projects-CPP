/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:39 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 11:06:47 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <cmath>
#include <iostream>
#include <exception>

class Bureaucrat {
	public:
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat & src);
		virtual ~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat & src);

		Bureaucrat &operator++(void);
		Bureaucrat operator++(int idx);

		Bureaucrat &operator--(void);
		Bureaucrat operator--(int idx);
		
		std::string getName(void) const;
		int getGrade(void) const;

		class GradeTooHighException : public std::exception{
			public:
        		const  char * what() const throw(){
            		return("Invalid grade: Too High (out of range : 1 - 150)");}};
		class GradeTooLowException : public std::exception {
			public:
				const char * what() const throw(){
					return("Invalid grade: Too Low (out of range : 1 - 150)");}};
	private:
		const std::string _name;
		int _grade;
	
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif