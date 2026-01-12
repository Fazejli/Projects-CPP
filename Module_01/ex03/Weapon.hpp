#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>
#include <iomanip>

classe Weapon(){
    private:
        std::string _type;

    Weapon();
    ~Weapon();
    public:
        std::string getType(void);
        setType(std::string type);
}

#endif