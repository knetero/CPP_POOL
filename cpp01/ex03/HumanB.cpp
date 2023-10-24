#include "HumanB.hpp"

HumanB::HumanB(){
}

HumanB::HumanB(std::string name):name(name), _weapon(nullptr){
}

void HumanB::setWeapon(Weapon& newWeapon){
   _weapon = &newWeapon;
}

void HumanB::attack(){
    std::cout << name << " attacks with their " << _weapon->getType() << "\n";
}

HumanB::~HumanB(){
}