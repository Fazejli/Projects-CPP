/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:59 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 10:50:56 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n========== Basic Tests ==========" << std::endl;
    DiamondTrap d1("Diamond");
	std::cout << "DiamondTrap created: " << d1.getName() << std::endl;
	d1.whoAmI();
	d1.attack("Enemy");
	d1.guardGate();
	d1.highFivesGuys();
	d1.takeDamage(20);
	d1.beRepaired(15);
    std::cout << d1.getName() << " has " << d1.getNrjPoints() << " nrj points left." << std::endl;
	
	std::cout << "\n========== Copy and Assignment Tests ==========" << std::endl;
	DiamondTrap d2(d1);
	std::cout << "DiamondTrap copied" << std::endl;
	DiamondTrap d3("Another");
	d3 = d1;
	d3.whoAmI();
	
	std::cout << "\n========== End of Tests ==========" << std::endl;
	return (0);
}