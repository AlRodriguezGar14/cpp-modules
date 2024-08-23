#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <typeinfo>
#include <unistd.h>

Base *generate() {
	int random = rand() % 3;

	switch (random) {
		case 0:
			std::cout << "Create class of type A" << std::endl;
			return new A();
		case 1:
			std::cout << "Create class of type B" << std::endl;
			return new B();
		case 2:
			std::cout << "Create class of type C" << std::endl;
			return new C();
		default:
			return NULL;
	}
}

void identify(Base *p) {
	if (dynamic_cast<A*>(p)) {
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B*>(p)) {
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C*>(p)) {
		std::cout << "C" << std::endl;
		return ;
	}
	std::cout << "Unknown" << std::endl;
}


void identify(Base &p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast &e) {
	}
	try {
		B &b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast &e) {
	}
	try {
		C &c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast &e) {
	}
	std::cout << "Unknown" << std::endl;
}

int main() {
	srand(time(0));

	Base *rand1 = generate();
	Base *rand2 = generate();
	Base *rand3 = generate();

	std::cout << "Identify rand1" << std::endl;
	identify(rand1);
	identify(*rand1);
	std::cout << "Identify rand2" << std::endl;
	identify(rand2);
	identify(*rand2);
	std::cout << "Identify rand3" << std::endl;
	identify(rand3);
	identify(*rand3);

	delete rand1;
	delete rand2;
	delete rand3;
}
