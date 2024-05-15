#include "headers/project_utils.hpp"
#include "headers/Contact.hpp"

void Contact::print_contact(size_t idx) {
	std::string row = format_column(to_str(idx)) + "|" + format_column(name) + "|" + format_column(last_name) + "|" + format_column(nickname) + "|";
	std::cout << row << std::endl;
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
	std::cout << std::endl;
	std::cout << "Adding new contact...:" << std::endl;
	name = get_input("NAME");
	last_name = get_input("LAST NAME");
	nickname = get_input("NICKNAME");
	phone_number = get_input("PHONE NUMBER");
	while (!is_valid_number(phone_number))
		phone_number = get_input("PHONE NUMBER");
	darkest_secret = get_input("DARKEST SECRET");
	creation_time = std::time(0);
	std::cout << "Contact added successfully" << std::endl;
	return (*this);
}

void Contact::print_contact() {
	std::cout << "Name: " << name << std::endl;
	std::cout << "Last Name: " << last_name << std::endl;
	std::cout << "Nickname: " << nickname << std::endl;
	std::cout << "Phone Number: " << phone_number << std::endl;
	std::cout << "Darkest Secret: " << darkest_secret << std::endl;
	std::cout << std::endl;
}

