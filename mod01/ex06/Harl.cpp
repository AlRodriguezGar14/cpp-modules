#include "Harl.hpp"
#include <cctype>
#include <cstring>

void    Harl::debug(void) {
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info(void) {
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void    Harl::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void) {
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

std::string toLower(std::string str) {

	std::string lower = "";
	for (std::string::size_type i = 0; i != str.length(); i++) {
		if (std::isupper(str[i]))
			lower += std::tolower(str[i]);
		else
			lower += str[i];
	}
	return lower;
}

int getIndex(std::string level) {

	std::string levels[4] = {"debug", "info", "warning", "error"};
	for (int i = 0; i != 5; i++) {
		if (level == levels[i])
			return i;
	}
	return -1;

}

void    Harl::complain(int t_idx) {

	void    (Harl::*complainLevel[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string labels[4] = { "[ DEBUG ]", "[ INFO ]", "[ WARNING ]", "[ ERROR ]" };

	std::cout << labels[t_idx] << std::endl;
	(this->*(complainLevel[t_idx]))();
	std::cout << std::endl;
}

ComplainLevel getLevel(const std::string& t_arg) {
	if (std::strcmp(t_arg.c_str(), "debug") == 0)
		return DEBUG;
	else if (std::strcmp(t_arg.c_str(), "info") == 0)
		return INFO;
	else if (std::strcmp(t_arg.c_str(), "warning") == 0)
		return WARNING;
	else if (std::strcmp(t_arg.c_str(), "error") == 0)
		return ERROR;
	else
		return NONE;
}


Harl::Harl() {};
Harl::Harl(const Harl &h) { (void)h; };
Harl& Harl::operator = (const Harl &t_h) { (void)t_h; return *this; };
Harl::~Harl() {};
