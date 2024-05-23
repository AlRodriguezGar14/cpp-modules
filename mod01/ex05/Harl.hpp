#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>
#include <string>

class Harl {
public:
	Harl();
	Harl(const Harl &t_h);
	Harl& operator = (const Harl &t_h);
	~Harl();
	void    complain(std::string t_level);
private:
	void    debug();
	void    info();
	void    warning();
	void    error();
};

#endif
