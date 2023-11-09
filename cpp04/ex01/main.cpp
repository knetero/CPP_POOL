#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main() 
{
    Animal* meta = new Animal();
	Animal* j = new Dog();
	Animal* i = new Cat();
	std::cout << j->Animal::getType() << " " << std::endl;
	std::cout << i->Animal::getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();
	WrongAnimal *wc = new WrongCat();
	std::cout << wc->WrongAnimal::getType() << " " << std::endl;
	wc->makeSound();
	Dog basic;
	{
		Dog tmp = basic;
        std::cout << &tmp << std::endl;
        std::cout << &basic << std::endl;
	}
	Animal *an[10];
	for(int i = 0; i < 5 ; i++)
	{
		an[i] = new Dog();
	}
	for(int i = 5; i < 10 ; i++)
	{
		an[i] = new Cat();
	}
	delete wc;
	delete i;
	delete j;
	delete meta;
	for (int i = 0; i < 10; i++)
	{
		delete an[i];
	}
	return (0);
}