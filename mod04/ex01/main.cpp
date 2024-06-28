#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define GREEN "\033[32m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define DEFAULT "\033[0m"

int main() {

	std::cout << GREEN << std::endl;
	Animal *animals[10];
	for (int i = 0; i < 5; ++i) {
		std::cout << MAGENTA << i << GREEN << std::endl;
		animals[i] = new Cat();
		std::cout << MAGENTA << i + 10 << GREEN << std::endl;
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
	std::cout << DEFAULT << std::endl;
	for (int i = 0; i < 10; ++i) {
		std::cout << MAGENTA << i << DEFAULT << std::endl;
		animals[i]->makeSound();
		delete animals[i];
	}
}
