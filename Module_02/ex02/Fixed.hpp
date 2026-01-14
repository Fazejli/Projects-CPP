#ifndef FIXED_HPP
#define FIXED_HPP

#include <iomanip>
#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed(void); //Default constructor
		Fixed(int const intNbr); //Numerical Int Constructor
		Fixed(float const floatNbr); //Numerical Float constructor
		Fixed(Fixed const & src); //Copy Constructor
		~Fixed(void); //Destructor

		Fixed & operator=( Fixed const & rhs ); //Copy assignment operator overload

		Fixed & operator+( Fixed const & rhs );
		Fixed & operator-( Fixed const & rhs );
		Fixed & operator*( Fixed const & rhs );
		Fixed & operator/( Fixed const & rhs );

		/*		Fixed & operator>( Fixed const & rhs );
		Fixed & operator<( Fixed const & rhs );
		Fixed & operator<=( Fixed const & rhs );
		Fixed & operator>=( Fixed const & rhs );
		Fixed & operator==( Fixed const & rhs );
		Fixed & operator!=( Fixed const & rhs );*/

		int getRawBits(void) const;
		void setRawBits(int const raw);

		float toFloat(void) const;
		int toInt(void) const;

	private:
		int	_value;
		static int const _nbBits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & i);

#endif