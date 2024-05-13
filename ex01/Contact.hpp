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
//	std::string	get_input(const std::string& prompt);
	bool		is_valid_number(const std::string& number);
public:
	Contact() {};
	Contact&		set_contact();
	void			print_contact_short(size_t idx);
	void			print_contact();
	std::string	get_name() const { return (name); };
	std::string	get_last_name() const { return (last_name); };
	~Contact() {};
};

void Contact::print_contact() {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Last Name: " << last_name << std::endl;
    std::cout << "Nickname: " << nickname << std::endl;
    std::cout << "Phone Number: " << phone_number << std::endl;
    std::cout << "Darkest Secret: " << darkest_secret << std::endl;
}

std::string format_column(const std::string& str) {

    std::string formatted = str;

    if (formatted.size() > 10) {
        formatted = formatted.substr(0, 9) + ".";
    }
    formatted = std::string(10 - formatted.size(), ' ') + formatted;
    return formatted;
}


void Contact::print_contact_short(size_t idx) {
    std::string row = format_column(std::to_string(idx)) + "|" + format_column(name) + "|" + format_column(last_name) + "|" + format_column(nickname) + "|";
    std::cout << row << std::endl;
}

void	clear_stdin(std::istream& in)
{
	in.clear();
	clearerr(stdin);
	std::cout << std::endl;
}

std::string get_input(const std::string& prompt) {
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

Contact&	Contact::set_contact() {
	name = get_input("NAME");
	last_name = get_input("LAST NAME");
	nickname = get_input("NICKNAME");
	while (!is_valid_number(phone_number))
		phone_number = get_input("PHONE NUMBER");
	darkest_secret = get_input("DARKEST SECRET");
	return (*this);
}

#endif
