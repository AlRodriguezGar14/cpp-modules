# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
public:
	Zombie();
	Zombie(const Zombie &z);
	Zombie(std::string name);
	Zombie& operator = (const Zombie &z);
	~Zombie();
	void 	announce(void);
	void	setName(std::string name);

private:
	std::string _name;
};

Zombie*	zombieHorde(int N, std::string name);

# endif
