#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "project_utils.hpp"
#include "Contact.hpp"

#include <iostream>
#include <cctype>
#include <string>


class PhoneBook {

public:
	PhoneBook() {};
	void	add();
	void	search();
	~PhoneBook() {};

private:
	Contact contact_list[8];
	void 	print_contacts();
};

#endif
