#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <string>

#include "project_utils.hpp"

class Contact {
private:
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	bool		is_valid_number(const std::string& number);
public:
	Contact() {};
	Contact&		set_contact();
	void			print_contact(size_t idx);
	void			print_contact();
	std::string	get_name() const { return (name); };
	std::string	get_last_name() const { return (last_name); };
	~Contact() {};
};

#endif
