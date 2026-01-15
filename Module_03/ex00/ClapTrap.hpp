#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap{

	public:

		ClapTrap(void); //Default constructor
		ClapTrap(ClapTrap & src); //Copy constructor
		ClapTrap(std::string name); //Assignation constructor
		~ClapTrap(); //Destructor

		ClapTrap & operator=(ClapTrap &other); //Assignation overload

		std::string getName();
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	private:

		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

};

//std::ostream & operator<<(std::ostream & o, ClapTrap const & i);

#endif