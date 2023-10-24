#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>
#include <iomanip>


class Weapon{
    private:
        std::string type;
    public:
        Weapon();
        Weapon(const std::string& type);
        const std::string& getType() const;
        void setType(std::string new_type);
        ~Weapon();
};


#endif