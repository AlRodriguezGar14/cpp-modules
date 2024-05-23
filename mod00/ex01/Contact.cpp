#include "Utils.hpp"
#include "Contact.hpp"

Contact::Contact() : _creation_time(0) {}

Contact::Contact(const Contact &contact) : _creation_time(contact._creation_time) {
    _name = contact._name;
    _last_name = contact._last_name;
    _nickname = contact._nickname;
    _phone_number = contact._phone_number;
    _darkest_secret = contact._darkest_secret;
}

Contact & Contact::operator = (const Contact &contact) {
    _name = contact._name;
    _last_name = contact._last_name;
    _nickname = contact._nickname;
    _phone_number = contact._phone_number;
    _darkest_secret = contact._darkest_secret;
	return (*this);
}

Contact::~Contact() {}

void Contact::print_contact(size_t idx) {
	std::string row = Utils::format_column(Utils::to_str(idx)) + "|" + Utils::format_column(_name) + "|" + Utils::format_column(_last_name) + "|" + Utils::format_column(_nickname) + "|";
	std::cout << row << std::endl;
}

bool Contact::_is_valid_number(const std::string& number)
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
    _name = Utils::get_input("NAME");
    _last_name = Utils::get_input("LAST NAME");
    _nickname = Utils::get_input("NICKNAME");
    _phone_number = Utils::get_input("PHONE NUMBER");
	while (!_is_valid_number(_phone_number))
        _phone_number = Utils::get_input("PHONE NUMBER");
    _darkest_secret = Utils::get_input("DARKEST SECRET");
    _creation_time = std::time(0);
	std::cout << "Contact added successfully" << std::endl;
	return (*this);
}

void Contact::print_contact() {
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Last Name: " << _last_name << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phone_number << std::endl;
	std::cout << "Darkest Secret: " << _darkest_secret << std::endl;
	std::cout << std::endl;
}

