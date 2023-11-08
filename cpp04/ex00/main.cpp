#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main( void )
{
    std::cout << "--------------- Animal ---------------" << std::endl;

    Animal* meta = new Animal();
    Animal* j = new Dog();
    Animal* i = new Cat();

    std::cout << "J Type: " << j->getType() << " " << std::endl;
    std::cout << "I Type: " << i->getType() << " " << std::endl;
    i->makeSound();
    meta->makeSound();

    delete  meta;
    delete  j;
    delete  i;

    std::cout << std::endl << "------------- Wrong Animal -------------" << std::endl;

    WrongAnimal *wrongAnimal = new WrongAnimal();
    WrongAnimal *wrongCat = new WrongCat();

    std::cout << "WrongAnimal Type: " << wrongAnimal->getType() << " " << std::endl;
    std::cout << "WrongCat Type: " << wrongCat->getType() << " " << std::endl;
    wrongAnimal->makeSound();
    wrongCat->makeSound();

    delete  wrongAnimal;
    delete  wrongCat;

    return 0;
}