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
	PhoneBook(const PhoneBook &t_phonebook);
	PhoneBook & operator = (const PhoneBook &t_phonebook);
	void	add();
	void	search();
	~PhoneBook();

private:
	Contact m_contact_list[8];
	void 	m_print_contacts();
};

#endif
