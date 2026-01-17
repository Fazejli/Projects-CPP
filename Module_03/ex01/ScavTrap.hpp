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
		void 		attack(const std::string& target);
};

std::ostream & operator<<(std::ostream & o, ScavTrap const & i);

#endif