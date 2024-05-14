#include "headers/project_utils.hpp"

std::string format_column(const std::string& str) {

	std::string formatted = str;

	if (formatted.size() > 10) {
		formatted = formatted.substr(0, 9) + ".";
	}
	formatted = std::string(10 - formatted.size(), ' ') + formatted;
	return formatted;
}

void	clear_stdin(std::istream& in) {
	in.clear();
	in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	clearerr(stdin);
	std::cout << std::endl;
}

std::string get_input(const std::string& prompt) {
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

