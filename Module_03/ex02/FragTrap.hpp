#ifndef FRAGTRAP_HPP
# define FRGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(FragTrap const & src);
		FragTrap(std::string name);
		~FragTrap();

		void highFivesGuys(void);

	private:
};

#endif