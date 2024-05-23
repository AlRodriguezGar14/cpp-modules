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
	void    complain(int t_idx);
private:
	void    debug();
	void    info();
	void    warning();
	void    error();
};

enum ComplainLevel {
	DEBUG = 0,
	INFO = 1,
	WARNING = 2,
	ERROR = 3,
	NONE = 4
};

ComplainLevel getLevel(const std::string& t_arg);
std::string toLower(std::string t_str);

#endif
