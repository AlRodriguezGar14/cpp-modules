#include "Utils.hpp"

Utils::Utils() {}
Utils::Utils(const Utils &t_utils) { (void)t_utils; }
Utils & Utils::operator = (const Utils &t_utils) { (void)t_utils; return (*this); }
Utils::~Utils() {}

std::string Utils::to_str(size_t t_nbr)
{
	std::stringstream ss;

	ss << t_nbr;
	return ss.str();
}

std::string Utils::format_column(const std::string& t_str) {

	std::string formatted = t_str;

	if (formatted.size() > 10) {
		formatted = formatted.substr(0, 9) + ".";
	}
	formatted = std::string(10 - formatted.size(), ' ') + formatted;
	return formatted;
}

void	Utils::clear_stdin(std::istream& t_in) {
	char c;

	t_in.clear();
	while (t_in.get(c) && c != '\n');
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
		std::cout << prompt << std::endl;
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
