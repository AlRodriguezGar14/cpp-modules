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
			contact_list[idx].print_contact_short(idx);
}

void	PhoneBook::search()
{
	size_t 		idx = 42;

	print_contacts();
	std::cout << "Select the index of the user info you want to display: ";
	std::cin >> idx;
	clear_stdin(std::cin);
	if (idx > 8)
		std::cout << "Invalid index. No info available" << std::endl;
	contact_list[idx].print_contact();

}
#endif
