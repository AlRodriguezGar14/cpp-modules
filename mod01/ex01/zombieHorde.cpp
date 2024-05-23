#include "Zombie.hpp"

Zombie*	zombieHorde(int t_n, std::string t_name) {
	Zombie* horde = new Zombie[t_n];
	for (int i = 0; i != t_n; ++i)
		horde[i].setName(t_name);
	return horde;
}

