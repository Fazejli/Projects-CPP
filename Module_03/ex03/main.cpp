/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:59 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 12:30:51 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "========== General info ==========" << std::endl;
    DiamondTrap d;
    d.whoAmI();
    std::cout << "EnergyPoint: " << d.getNrjPoints() << std::endl;
    std::cout << "HitPoints: " << d.getHitPoints() << std::endl;
    std::cout << "AttackDamage: " << d.getAttackDamage() << std::endl;
    
	std::cout << "\n\n========== Testing member functions ==========" << std::endl;
    DiamondTrap d1("Diamond");
	d1.whoAmI();
	d1.attack("Enemy"); // lost 1 nrj points
	d1.guardGate();
	d1.highFivesGuys();
	d1.takeDamage(20); // lost 20 hp
	d1.beRepaired(15); // lost 1 nrj point and gain 15 hp
    std::cout << d1.getName() << " has " << d1.getNrjPoints() << " nrj points left." << std::endl;
	std::cout << d1.getName() << " has " << d1.getHitPoints() << " hp left." << std::endl;
    
	std::cout << "\n\n========== Copy and Assignment Tests ==========" << std::endl;
	DiamondTrap d2(d1);
	DiamondTrap d3("Another");
	d3 = d1;
	d3.whoAmI();
	
	std::cout << "\n\n========== End of Tests ==========" << std::endl;
	return (0);
}