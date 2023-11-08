#include "FragTrap.hpp"

FragTrap::FragTrap(){
    std::cout << "FragTrap default constructer"<<std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap &other){
    std::cout << "Copy assignment operator called" << std::endl;
    this->Name = other.Name;
    this->Hit_points = other.Hit_points;
    this->Energy_points = other.Energy_points;
    this->Attack_damage = other.Attack_damage;
    return *this;
}

FragTrap::FragTrap(const FragTrap &other){
    *this = other;
    std::cout << "Copy constructor called" << std::endl;
}

FragTrap::FragTrap(const std::string name){
    Name = name;
    Hit_points = 100;
    Energy_points = 100;
    Attack_damage = 30;
    std::cout << "FragTrap " << Name << " constructed." << std::endl;
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap " << Name << " is destructed." << std::endl;
}

void FragTrap::attack(const std::string& target){
    if (Energy_points >= 1){
        Energy_points--;
        std::cout << "FragTrap " << Name << " attacks! " << target << ", causing " << Attack_damage << " points of damage! " << std::endl;
    }
    else
        std::cout << "FragTrap " << Name << " is out of energy and can't attack!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << "FragTrap " << Name << " requests a high five! " << std::endl;
}