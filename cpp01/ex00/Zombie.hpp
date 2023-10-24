#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>


class Zombie{
    private:
        std::string name;
    public:
        Zombie(std::string zombieName);
        void announce(void);
        ~Zombie();
};
Zombie* newZombie(std::string name );
void randomChump( std::string name );


#endif
