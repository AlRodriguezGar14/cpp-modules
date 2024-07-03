#include "Utils.hpp"
#include "Contact.hpp"

Contact::Contact() : m_creation_time(0) {}

Contact::Contact(const Contact &t_contact) : m_creation_time(t_contact.m_creation_time) {
    m_name = t_contact.m_name;
    m_last_name = t_contact.m_last_name;
    m_nickname = t_contact.m_nickname;
    m_phone_number = t_contact.m_phone_number;
    m_darkest_secret = t_contact.m_darkest_secret;
}

Contact & Contact::operator = (const Contact &t_contact) {
    m_name = t_contact.m_name;
    m_last_name = t_contact.m_last_name;
    m_nickname = t_contact.m_nickname;
    m_phone_number = t_contact.m_phone_number;
    m_darkest_secret = t_contact.m_darkest_secret;
	m_creation_time = t_contact.m_creation_time;
	return (*this);
}

Contact::~Contact() {}

void Contact::print_contact(size_t t_idx) {
	std::string row = Utils::format_column(Utils::to_str(t_idx)) + "|" + Utils::format_column(m_name) + "|" + Utils::format_column(m_last_name) + "|" + Utils::format_column(m_nickname) + "|";
	std::cout << row << std::endl;
}

bool Contact::m_is_valid_number(const std::string& t_number)
{
	if (t_number.empty() || t_number.size() != 9)
		return (std::cout << "Invalid t_number" << std::endl, false);
	for (size_t idx = 0; idx != t_number.size(); ++idx)
		if (!std::isdigit(t_number[idx]))
			return (std::cout << "Invalid t_number" << std::endl, false);
	return (true);
}

Contact&	Contact::set_contact() {
	std::cout << std::endl;
	std::cout << "Adding new contact...:" << std::endl;
    m_name = Utils::get_input("NAME");
    m_last_name = Utils::get_input("LAST NAME");
    m_nickname = Utils::get_input("NICKNAME");
    m_phone_number = Utils::get_input("PHONE NUMBER");
	while (!m_is_valid_number(m_phone_number))
        m_phone_number = Utils::get_input("PHONE NUMBER");
    m_darkest_secret = Utils::get_input("DARKEST SECRET");
    m_creation_time = std::time(0);
	return (*this);
}

void Contact::print_contact() {
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Last Name: " << m_last_name << std::endl;
	std::cout << "Nickname: " << m_nickname << std::endl;
	std::cout << "Phone Number: " << m_phone_number << std::endl;
	std::cout << "Darkest Secret: " << m_darkest_secret << std::endl;
	std::cout << std::endl;
}


std::time_t Contact::get_timestamp() const { return (m_creation_time); };

std::string	Contact::get_name() const { return (m_name); };

std::string Contact::get_phone_number() const { return (m_phone_number); };