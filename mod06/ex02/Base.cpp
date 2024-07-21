#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() : m_classType("default base") {}
Base::Base(const Base& t_Base) : m_classType(t_Base.m_classType) {}
Base& Base::operator=(const Base& t_Base) {
	if (this != &t_Base) {
		m_classType = t_Base.m_classType;
	}
	return *this;
}
Base::~Base() {}

std::string Base::getClassType() const {
	return m_classType;
}

Base* Base::generate() {

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

template <typename T>
bool Base::checkType(Base* p, std::string message) {
	if (dynamic_cast<T*>(p)) {
		std::cout << message << std::endl;
		return true;
	}
	return false;
}

void Base::identify(Base* p) {
	if (!p) {
		std::cout << "NULL pointer" << std::endl;
		return;
	}
	if (checkType<A>(p, "A")
		|| checkType<B>(p, "B")
		|| checkType<C>(p, "C"))
		return ;
	std::cout << "Unknown class" << std::endl;
}

void Base::identify(Base& p) {
	Base::identify(&p);
}
