#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {};

PhoneBook::PhoneBook(const PhoneBook &phonebook) {
	for (size_t idx = 0; idx != 8; ++idx)
	{
		if (!phonebook.contact_list[idx].get_name().empty())
			contact_list[idx] = phonebook.contact_list[idx];
		else
			break ;
	}
}

PhoneBook & PhoneBook::operator = (const PhoneBook &phonebook) {
	for (size_t idx = 0; idx != 8; ++idx)
	{
		if (!phonebook.contact_list[idx].get_name().empty())
			contact_list[idx] = phonebook.contact_list[idx];
		else
			break ;
	}
	return (*this);
}

PhoneBook::~PhoneBook() {}

void	PhoneBook::add() {
	for (size_t idx = 0; idx != 7; ++idx)
	{
		if (contact_list[idx].get_name().empty())
		{
			contact_list[idx] = Contact().set_contact();
			return ;
		}
	}
	size_t  oldest_idx = 0;
	for (size_t idx = 0; idx != 8; ++idx)
	{
		if (contact_list[idx].get_timestamp() < contact_list[oldest_idx].get_timestamp())
			oldest_idx = idx;
	}
	contact_list[oldest_idx] = Contact().set_contact();
}

void	PhoneBook::print_contacts()
{
	for (size_t idx = 0; idx != 8; ++idx)
		if (!contact_list[idx].get_name().empty())
			contact_list[idx].print_contact(idx + 1);
}

void	PhoneBook::search()
{
	size_t 		idx = 42;

	print_contacts();
	if (contact_list[0].get_name().empty())
	{
		std::cout << std::endl << "The PhoneBook is empty." << std::endl;
		return ;
	}
	std::cout << "Select the index of the user info you want to display: ";
	std::cin >> idx;
	Utils::clear_stdin(std::cin);
	if (idx > 8 || idx < 1 || contact_list[idx - 1].get_name().empty()) {
		std::cout << "Invalid index. No info available" << std::endl;
		return ;
	}
	contact_list[idx - 1].print_contact();
}
