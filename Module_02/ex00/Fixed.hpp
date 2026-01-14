#ifndef FIXED_HPP
#define FIXED_HPP

#include <iomanip>
#include <iostream>

class Fixed{
	public:
		Fixed(void); //Default constructor
		Fixed(Fixed & src); //Copy Constructor
		~Fixed(void); //Destructor

		Fixed & operator=( Fixed & rhs ); //Copy assignment operator overload
		int getRawBits(void) const;
		void setRawBits(int const raw);

	private:
		int	_fixedPointValue;
		static int const _nbBits = 8;
};

#endif