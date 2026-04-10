/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadwa <fadwa@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/07 14:00:35 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/10 14:46:16 by fadwa            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(){
	const Bureaucrat a;
	Bureaucrat b("player", 1);
	
	std::cout << a << std::endl;
	std::cout << b << std::endl;

	try {
		Bureaucrat c("Bob", 149);
		Bureaucrat d = c;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << c++ << std::endl;
		
		std::cout << b++ << std::endl;
		std::cout << a << std::endl;
	}
	catch (const std::exception & e){
		std::cerr << e.what() << std::endl;
	}
	return (0);
}