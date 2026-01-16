#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

# include <iostream>
# include <string>

class ClapTrap{

	public:

		ClapTrap(void); //Default constructor
		ClapTrap(ClapTrap const & src); //Copy constructor
		ClapTrap(std::string name); //Assignation constructor
		~ClapTrap(); //Destructor

		virtual ClapTrap & operator=(ClapTrap const & other); //Assignation overload

		virtual std::string getName() const;
		virtual int			getHitPoints() const;
		virtual int			getNrjPoints() const;
		virtual int			getAttackDamage() const;

		virtual void attack(const std::string& target);
		virtual void takeDamage(unsigned int amount);
		virtual void beRepaired(unsigned int amount);

	protected:

		std::string _name;
		int			_hitPoints;
		int			_energyPoints;
		int			_attackDamage;

};

std::ostream & operator<<(std::ostream & o, ClapTrap const & i);

#endif
