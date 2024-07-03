#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {};

PhoneBook::PhoneBook(const PhoneBook &t_phonebook) {
	for (size_t idx = 0; idx != 8; ++idx)
	{
		if (!t_phonebook.m_contact_list[idx].get_name().empty())
            m_contact_list[idx] = t_phonebook.m_contact_list[idx];
		else
			break ;
	}
}

PhoneBook & PhoneBook::operator = (const PhoneBook &t_phonebook) {
	for (size_t idx = 0; idx != 8; ++idx)
	{
		if (!t_phonebook.m_contact_list[idx].get_name().empty())
            m_contact_list[idx] = t_phonebook.m_contact_list[idx];
		else
			break ;
	}
	return (*this);
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add() {
	Contact newContact = Contact().set_contact();
	for (size_t idx = 0; idx != 8; ++idx) {
		if (m_contact_list[idx].get_phone_number() == newContact.get_phone_number())
		{
			std::cout << "Contact with this number already exists" << std::endl;
			return ;
		}
		if (m_contact_list[idx].get_name().empty())
		{
            m_contact_list[idx] = newContact;
			std::cout << "Contact added successfully" << std::endl;
			return ;
		}
	}
	size_t  oldest_idx = 0;
	for (size_t idx = 0; idx != 8; ++idx) {
		if (m_contact_list[idx].get_timestamp() < m_contact_list[oldest_idx].get_timestamp())
			oldest_idx = idx;
	}
    m_contact_list[oldest_idx] = newContact;
	std::cout << "Contact added successfully" << std::endl;
}

void	PhoneBook::m_print_contacts()
{
	for (size_t idx = 0; idx != 8; ++idx)
		if (!m_contact_list[idx].get_name().empty())
			m_contact_list[idx].print_contact(idx + 1);
}

void	PhoneBook::search()
{
	size_t 		idx = 42;

    m_print_contacts();
	if (m_contact_list[0].get_name().empty())
	{
		std::cout << std::endl << "The PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << "Select the index of the user info you want to display:" << std::endl;
	std::cin >> idx;
	Utils::clear_stdin(std::cin);
	if (idx > 8 || idx < 1 || m_contact_list[idx - 1].get_name().empty()) {
		std::cout << "Invalid index. No info available" << std::endl;
		return ;
	}
	m_contact_list[idx - 1].print_contact();
}
