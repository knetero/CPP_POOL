#include "Zombie.hpp"

Zombie::Zombie(std::string zombieName){
     name = zombieName;
}

void Zombie::announce(void){
    std::cout << " BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {
    std::cout << "Zombie " << name << " has been destroyed." << std::endl;
}