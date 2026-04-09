/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 13:51:11 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 14:47:00 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>

class ShrubberyCreationForm : public AForm{
    private:
        std::string _target;
    
    public :
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm & src);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm & operator=(const ShrubberyCreationForm & src);
        
        void execute(Bureaucrat const & executor);
        //EXEC => Creates a file <target>_shrubbery in the working directory
        //and writes ASCII trees inside it.
};

#endif