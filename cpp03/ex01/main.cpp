#include "ScavTrap.hpp"

int main() {
    ClapTrap claptrap("CL4P-TP");
    ScavTrap scavtrap("SGT-TP");

    claptrap.attack("Bandit");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    scavtrap.attack("Bandit");
    scavtrap.guardGate();

    return 0;
}