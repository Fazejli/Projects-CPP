/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 19:53:49 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 20:05:32 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>

#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Intern {
    public:
        Intern();
        Intern(const Intern & s);
        ~Intern();

        Intern &operator=(const Intern & s);
        AForm *makeForm(std::string name, std::string target);
};


/*
private:
    typedef AForm* (*FormCreator)(std::string target);

    static AForm* createShrubbery(std::string target);
    static AForm* createRobotomy(std::string target);
    static AForm* createPresidential(std::string target);
};

#endif*/
#endif