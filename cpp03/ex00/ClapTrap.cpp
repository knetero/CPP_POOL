#include "ClapTrap.hpp"

ClapTrap::ClapTrap(){
}

ClapTrap::ClapTrap(std::string name): Name(name), Hit_points(10), Energy_points(10), Attack_damage(0){
    std::cout << "ClapTrap " << Name << " is Created!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &other){
    std::cout << "Copy assignment operator called" << std::endl;
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    return *this;
}

ClapTrap::ClapTrap(const ClapTrap &other){
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){

    if (Energy_points >= 1){
        Energy_points--;
        std::cout << "ClapTrap " << Name << " attacks! " << target << ", causing " << Attack_damage << " points of damage! " << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " is out of energy and can't attack!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount){
    if(Hit_points > 0)
    {
        if(amount >= Hit_points)
            Hit_points = 0;
        else
            Hit_points -= amount;
        std::cout << "ClapTrap " << Name << " takes " << amount << " points of damage, Current Hit points: " << Hit_points << std::endl;
    }
    else
        std::cout << "ClapTrap " << Name << " has no hit points left!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
    Hit_points += amount;
    Energy_points--;
    std::cout << "ClapTrap " << Name << " has been Repaired with : " << amount << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "ClapTrap " << Name << " is destroyed!" << std::endl;
}