#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Utils.hpp"
#include "Contact.hpp"

#include <iostream>
#include <cctype>
#include <string>


class PhoneBook {

public:
	PhoneBook();
	PhoneBook(const PhoneBook &phonebook);
	PhoneBook & operator = (const PhoneBook &phonebook);
	void	add();
	void	search();
	~PhoneBook();

private:
	Contact contact_list[8];
	void 	print_contacts();
};

#endif
