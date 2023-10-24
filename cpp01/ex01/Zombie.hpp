#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>


class Zombie{
    private:
        std::string name;

    public:
        Zombie();
        Zombie(std::string zombieName);
        void announce(void);
        ~Zombie();
};
Zombie* zombieHorde( int N, std::string name );


#endif
