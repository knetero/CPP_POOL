#include "Character.hpp"

Character::Character(std::string const& name)
{
    this->name = name;
    for (int i = 0; i < 4; i++){
        inventory[i] = NULL;
    }
    // std::cout << "Character " << this->getName() << " created" << std::endl;
}

Character::Character(const Character &other){
    *this = other;
    // std::cout << "Character " << this->getName() << " created" << std::endl;
}

Character& Character::operator=(const Character &other){
    // std::cout << "Character Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        for (int i = 0; i < 4; i++){
            this->inventory[i] = other.inventory[i];
        }
    }
    return *this;
}

std::string const & Character::getName() const{
    return name;
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 4; i++)
    {
        if (inventory[i] == NULL)
        {
            inventory[i] = m;
            // std::cout << "Character " << this->getName() << " equipped with " << m->getType() << std::endl;
            return;
        }
    }
    // std::cout << "Character " << this->getName() << " can't equip " << m->getType() << std::endl;
}

void Character::unequip(int idx)
{
    if(inventory[idx]){
        delete inventory[idx];
        inventory[idx] = NULL;
    }
    // std::cout << "Character " << this->getName() << " can't unequip " << std::endl;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx >= 0 && idx < 4 && inventory[idx] != NULL)
    {
        inventory[idx]->use(target);
    }
}
Character::~Character()
{
    for (int i = 0; i < 4; i++){
        delete inventory[i];
    }
}