#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "project_utils.hpp"
#include "Contact.hpp"

#include <iostream>
#include <cctype>
#include <string>


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

#endif
