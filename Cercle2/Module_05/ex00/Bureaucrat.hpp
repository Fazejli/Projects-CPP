/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:39 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/07 15:01:30 by fadzejli         ###   ########.fr       */
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
		
		Bureaucrat GradeTooHighException(void);
		Bureaucrat GradeTooLowException(void);
		
	private:
		const std::string _name;
		int _grade;
	
};

std::ostream &operator<<(std::ostream &o, const Bureaucrat &b);

#endif