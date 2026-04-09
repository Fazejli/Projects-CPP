/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/09 13:43:03 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(){
    // Test constructeur valide
    Form f1("TaxForm", 50, 25);
    std::cout << f1 << std::endl;

    // Test grade out of range
    try {
        Form f2("BadForm", 0, 25);
    }
    catch (const std::exception &e){
        std::cerr << "Form creation failed: " << e.what() << std::endl;
    }

    // Test signature réussie
    try {
        Bureaucrat alice("Alice", 30);
        std::cout << alice << std::endl;
        alice.signForm(f1);
        std::cout << f1 << std::endl;
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    // Test signature échouée (grade trop bas)
    try {
        Form f3("SecretForm", 10, 5);
        Bureaucrat bob("Bob", 100);
        std::cout << bob << std::endl;
        bob.signForm(f3);
    }
    catch (const std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return (0);
}