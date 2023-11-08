#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main(void)
{
    // AAnimal animal;
    AAnimal* j = new Dog();
    AAnimal* i = new Cat();

    delete j;
    delete i;


    AAnimal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
    for ( int i = 0; i < 4; i++ ) {
        delete animals[i];
    }
}