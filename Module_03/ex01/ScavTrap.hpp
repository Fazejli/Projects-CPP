/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fadzejli <fadzejli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 14:52:19 by fadzejli          #+#    #+#             */
/*   Updated: 2026/04/03 10:26:54 by fadzejli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <string>
#include <iostream>

class ScavTrap : public ClapTrap {
	public:
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const & src);
		ScavTrap();
		~ScavTrap();

		ScavTrap & 	operator=(ScavTrap const & other);
		void 		guardGate();
		void	attack(const std::string& target);

		void setHitPoints(int hp);
		void setNrjPoints(int energy);
		void setAttackDamage(int damage);
};

std::ostream & operator<<(std::ostream & o, ScavTrap const & i);

#endif