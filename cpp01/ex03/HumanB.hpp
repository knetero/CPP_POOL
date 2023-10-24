#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include <iomanip>
#include "Weapon.hpp"

class HumanB{
    private:
        std::string name;
        Weapon*     _weapon;
    public:
        HumanB();
        HumanB(std::string name);
        void attack();
        void setWeapon(Weapon& newWeapon);
        ~HumanB();
};

 
#endif