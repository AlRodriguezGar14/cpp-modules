#include <iostream>
#include <string>

class Harl {
public:
	Harl();
	Harl(const Harl &h);
	Harl& operator = (const Harl &h);
	~Harl();
	void    complain(int i);
private:
	void    debug(void);
	void    info(void);
	void    warning(void);
	void    error(void);
};

enum ComplainLevel {
	DEBUG = 0,
	INFO = 1,
	WARNING = 2,
	ERROR = 3,
	NONE = 4
};

ComplainLevel getLevel(const std::string& arg);
std::string toLower(std::string str);
