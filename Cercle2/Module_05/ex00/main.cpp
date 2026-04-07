/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/07 15:31:38 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	const Bureaucrat a;
	Bureaucrat b("player", 149);
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try {
		Bureaucrat c("Bob", 151);
		Bureaucrat d = c;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << b-- << std::endl;
		std::cout << b-- << std::endl;
		std::cout << b-- << std::endl;
	}
	catch (const std::runtime_error & e){
		std::cerr << "Erreur : " << e.what() << std::endl;
	}
	
	std::cout << "Fin du prog" << std::endl;
	return (0);
}