#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <iostream>
#include <unistd.h>

int main() {
	srand(time(0));
	Base generator;

	Base* rand1 = generator.generate();
	usleep(100);
	Base* rand2 = generator.generate();
	usleep(100);
	Base* rand3 = generator.generate();

	generator.identify(rand1);
	generator.identify(rand2);
	generator.identify(rand3);

	delete rand1;
	delete rand2;
	delete rand3;

	std::cout << "Not pointers" << std::endl;
	A a;
	B b;
	C c;
	generator.identify(a);
	generator.identify(b);
	generator.identify(c);
}
