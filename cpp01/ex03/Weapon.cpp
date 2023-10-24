#include "Weapon.hpp"

Weapon::Weapon(){
}
Weapon::Weapon(const std::string& type){
    this->type = type;
}

void    Weapon::setType(std::string new_type){
    type = new_type;
}

const std::string& Weapon::getType() const{
    return type;
}

Weapon::~Weapon(){
}