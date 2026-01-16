#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap{

	public:
		ClapTrap(void); //Default constructor
		ClapTrap(ClapTrap const & src); //Copy constructor
		ClapTrap(std::string name); //Assignation constructor
		virtual ~ClapTrap(); //Destructor

		ClapTrap & operator=(ClapTrap const & other); //Assignation overload

		std::string getName() const;
		int			getHitPoints() const;
		int			getNrjPoints() const;
		int			getAttackDamage() const;

		virtual void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

	protected:
		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

};

std::ostream & operator<<(std::ostream & o, ClapTrap const & i);

#endif
