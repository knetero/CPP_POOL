#include "ClapTrap.hpp"

int main() {
    ClapTrap claptrap("CL4P-TP");

    claptrap.attack("Bandit");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);
    claptrap.attack("Bandit");
    claptrap.takeDamage(12);
    return 0;
}
