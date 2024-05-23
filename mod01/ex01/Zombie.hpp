# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie {
public:
	Zombie();
	Zombie(const Zombie &t_z);
	Zombie(std::string t_name);
	Zombie& operator = (const Zombie &t_z);
	~Zombie();
	void 	announce();
	void	setName(std::string t_name);

private:
	std::string m_name;
};

Zombie*	zombieHorde(int t_n, std::string t_name);

# endif
