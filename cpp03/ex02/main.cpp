#include "FragTrap.hpp"

int main() {
    ClapTrap claptrap;
    FragTrap fragtrap("FR4G-TP");

    claptrap.attack("Bandit");
    claptrap.takeDamage(5);
    claptrap.beRepaired(3);

    fragtrap.attack("Bandit");
    fragtrap.takeDamage(5);
    fragtrap.beRepaired(3);
    fragtrap.highFivesGuys();

    return 0;
}