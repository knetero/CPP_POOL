#include "Zombie.hpp"

int main()
{
    Zombie* z1 = newZombie("foo");
    z1->announce();
    delete z1;
    
    randomChump("Bar");
}