#ifndef SAMPLE_HPP
# define SAMPLE_HPP

# include <iostream>

class Sample {
	public:

		Sample(void);  //Constructeur par defaut
		Sample(int const n);
		Sample(Sample const & src); //Constructeur par copie
		~Sample(void);  //Destructeur

		Sample &	operator=( Sample const & rhs);  //Operateur d'assignation
		
		int	getFoo(void) const;

	private:
		int _foo;
};

//Pas obligatoire (Surcharge de chevrons gauches):
std::ostream & operator<<(std::ostream & o, Sample const & i);

#endif