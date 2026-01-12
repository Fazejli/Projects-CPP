#include "HumanA.hpp"

void HumanA::HumanA(std::string name, Weapon& weapon) ; _weapon(weapon);
{
    _name = name;
}

void HumanA::~HumanA(){
}

void Weapon::attack(void){
    std::cout << _name << " attacks with their ";
    std::cout << _weapon.getType() << std::endl;
}