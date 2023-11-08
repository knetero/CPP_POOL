#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
}

ScavTrap& ScavTrap::operator=(const ScavTrap &other){
    std::cout << "Copy assignment operator called" << std::endl;
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    return *this;
}

ScavTrap::ScavTrap(const ScavTrap &other){
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name){
    Hit_points = 100;
    Energy_points = 50;
    Attack_damage = 20;
    std::cout << "ScavTrap " << Name << " constructed." << std::endl;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap " << Name << " is destructed." << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (Energy_points >= 1){
        Energy_points--;
        std::cout << "ScavTrap " << Name << " attacks! " << target << ", causing " << Attack_damage << " points of damage! " << std::endl;
    }
    else
        std::cout << "ScavTrap " << Name << " is out of energy and can't attack!" << std::endl;
}

void ScavTrap::guardGate(){
    std::cout << "ScavTrap " << Name << " is now in Gate keeper mode. " << std::endl;
}
