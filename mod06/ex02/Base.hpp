#ifndef BASE_HPP
#define BASE_HPP

#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>

class A;
class B;
class C;

class Base {
protected:
	std::string m_classType;
public:
	Base ();
	Base (const Base &t_Base);
	Base& operator = (const Base &t_Base);
	virtual ~Base ();
	virtual std::string getClassType () const;

	Base* generate(void);
	void identify(Base* p);
	void identify(Base& p);

	template <typename T>
	bool checkType(Base* p, std::string message);

};

#endif
