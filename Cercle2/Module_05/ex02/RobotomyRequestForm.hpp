/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:50:18 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 14:37:06 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class RobotomyRequestForm : public AForm{
    private:
        std::string _target;
    
    public :
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string target);
        RobotomyRequestForm(const RobotomyRequestForm & src);
        ~RobotomyRequestForm();

        RobotomyRequestForm & operator=(const RobotomyRequestForm & src);

        void execute(Bureaucrat const & executor);
        //EXEC => Makes some drilling noises, then informs that <target> has been robotomized
        //successfully 50% of the time. Otherwise, it informs that the robotomy failed.
};

#endif