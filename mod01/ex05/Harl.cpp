#include "Harl.hpp"
#include <cctype>

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

std::string toLower(std::string t_str) {

	std::string lower = "";
	for (std::string::size_type i = 0; i != t_str.length(); i++) {
		if (std::isupper(t_str[i]))
			lower += std::tolower(t_str[i]);
		else
			lower += t_str[i];
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

void    Harl::complain(std::string t_level) {

	void    (Harl::*complainLevel[4]) (void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string labels[4] = { "[ DEBUG ]", "[ INFO ]", "[ WARNING ]", "[ ERROR ]" };
	int i = getIndex(toLower(t_level));
	if (i != -1)
	{
		std::cout << labels[i] << std::endl;
		(this->*(complainLevel[i]))();
	}
	else
		std::cout << "Invalid complain t_level" << std::endl;
}

Harl::Harl() {};
Harl::Harl(const Harl &t_h) { (void)t_h; };
Harl& Harl::operator = (const Harl &h) { (void)h; return *this; };
Harl::~Harl() {};
