#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define DEFAULT "\033[0m"

#define ANIMALS_NUM 10

int main() {

	// This won't compile:
	// Animal animal;

	std::cout << GREEN << std::endl;
	Animal *animals[ANIMALS_NUM];
	for (int i = 0; i < ANIMALS_NUM / 2; ++i) {
		std::cout << MAGENTA << i << GREEN << std::endl;
		animals[i] = new Cat();
		std::cout << MAGENTA << i + ANIMALS_NUM / 2 << GREEN << std::endl;
		animals[i + 5] = new Dog();
	}
	std::cout << DEFAULT << std::endl;

	std::cout << BLUE << std::endl;
	animals[0]->makeSound();
	std::cout << animals[0]->getBrainIdea(100) << std::endl;
	std::cout << animals[0]->getBrainIdea(99) << std::endl;
	animals[0]->setBrainIdea("I am a cat", 10);
	std::cout << animals[0]->getBrainIdea(10) << std::endl;
	animals[9]->makeSound();
	std::cout << animals[9]->getBrainIdea(42) << std::endl;
	std::cout << animals[9]->getType() << std::endl;
	std::cout << MAGENTA << std::endl;
	std::cout << "Create an Animal outside of the list" << std::endl;
	Cat roninCat;
	roninCat.makeSound();
	std::cout << "The idea 10 of the created cat is: " << roninCat.getBrainIdea(10) << std::endl;
	std::cout << "Copy the Cat from the list to the Animal outside of the list" << std::endl;
	roninCat = *dynamic_cast<Cat*>(animals[0]);
	std::cout << "The idea 10 of the created cat is: " << roninCat.getBrainIdea(10) << std::endl;
	std::cout << DEFAULT << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << MAGENTA << i << DEFAULT << std::endl;
		animals[i]->makeSound();
		delete animals[i];
	}
}
