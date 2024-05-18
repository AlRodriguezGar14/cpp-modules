#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <ctime>

#include "Utils.hpp"

class Contact {

public:
	Contact();
	Contact(const Contact &contact);
	Contact & operator = (const Contact &contact);
	Contact&		set_contact();
	void			print_contact(size_t idx);
	void			print_contact();
	std::time_t     get_timestamp() const { return (creation_time); };
	std::string	get_name() const { return (name); };
	~Contact();

private:
	std::string	name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	std::time_t	creation_time;
	bool		is_valid_number(const std::string& number);
};


#endif
