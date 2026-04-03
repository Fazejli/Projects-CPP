#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>


class Fixed {
    public:
        Fixed(void);
        ~Fixed();
        Fixed( Fixed &other);

        const Fixed & operator=( Fixed &other);

        int getRawBits(void) const;
        void setRawBits(int const raw);

    private:
        int _value;
        static const int _nbBits = 8;
};

#endif