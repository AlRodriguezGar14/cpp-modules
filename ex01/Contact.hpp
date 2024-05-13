#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <string>

class Contact {
private:
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	std::string	get_input(const std::string& prompt);
	bool		is_valid_number(const std::string& number);
public:
	Contact();
	~Contact() {};
};


void	clear_stdin(std::istream& in)
{
	in.clear();
	clearerr(stdin);
	std::cout << std::endl;
}

std::string Contact::get_input(const std::string& prompt) {
	std::string input;
	size_t 		idx;
	while (42)
	{
		idx = 0;
		std::cout << prompt << ": ";
		if (!std::getline(std::cin, input) || std::cin.eof())
			clear_stdin(std::cin);
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

bool Contact::is_valid_number(const std::string& number)
{
	if (number.empty() || number.size() != 9)
		return (std::cout << "Invalid number" << std::endl, false);
	for (size_t idx = 0; idx != number.size(); ++idx)
		if (!std::isdigit(number[idx]))
			return (std::cout << "Invalid number" << std::endl, false);
	return (true);
}

Contact::Contact() {
	name = get_input("NAME");
	last_name = get_input("LAST NAME");
	nickname = get_input("NICKNAME");
	while (!is_valid_number(phone_number))
		phone_number = get_input("PHONE NUMBER");
	darkest_secret = get_input("DARKEST SECRET");
}

#endif
