#include "Utils.hpp"

Utils::Utils() {}
Utils::Utils(const Utils &utils) { (void)utils; }
Utils & Utils::operator = (const Utils &utils) { (void)utils; return (*this); }
Utils::~Utils() {}

std::string Utils::to_str(size_t nbr)
{
	std::stringstream ss;

	ss << nbr;
	return ss.str();
}

std::string Utils::format_column(const std::string& str) {

	std::string formatted = str;

	if (formatted.size() > 10) {
		formatted = formatted.substr(0, 9) + ".";
	}
	formatted = std::string(10 - formatted.size(), ' ') + formatted;
	return formatted;
}

void	Utils::clear_stdin(std::istream& in) {
	char c;

	in.clear();
	while (in.get(c) && c != '\n');
	clearerr(stdin);
	std::cout << std::endl;
}

std::string Utils::get_input(const std::string& prompt) {
	std::string input;
	size_t 		idx;
	while (42)
	{
		std::cin.clear();
		idx = 0;
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, input) || std::cin.eof())
		{
			clear_stdin(std::cin);
			input.clear();
			continue ;
		}
		while (input[idx] && std::isspace(input[idx]))
			idx++;
		if (input.empty() || idx == input.size())
			std::cout << "Invalid input" << std::endl;
		else
			break ;
	}
	std::cin.clear();
	return (input);
}

