#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <cctype>
#include <string>
#include "Contact.hpp"

class PhoneBook {
private:
	Contact contact_list[9];
	void 	print_contacts();
public:
	PhoneBook() {};
	void	add();
	void	search();
	~PhoneBook() {};
};

void	PhoneBook::add() {
	for (size_t idx = 0; idx != 8; ++idx)
	{
		if (contact_list[idx].get_name().empty())
		{
			contact_list[idx] = Contact().set_contact();
			return ;
		}
	}
	contact_list[8] = Contact().set_contact();
}

void	PhoneBook::print_contacts()
{
	for (size_t idx = 0; idx != 8; ++idx)
		if (!contact_list[idx].get_name().empty())
			contact_list[idx].print_contact(idx);
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
	clear_stdin(std::cin);
	if (idx > 8 || contact_list[idx].get_name().empty()) {
		std::cout << "Invalid index. No info available" << std::endl;
		return ;
	}
	contact_list[idx].print_contact();
}

#endif
