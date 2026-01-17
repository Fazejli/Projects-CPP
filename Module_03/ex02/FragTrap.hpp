#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

class FragTrap : public ClapTrap {
	public:
		FragTrap();
		FragTrap(FragTrap const & src);
		FragTrap(std::string name);
		~FragTrap();

		FragTrap & operator=(FragTrap const & other);

		void highFivesGuys(void);
};

#endif