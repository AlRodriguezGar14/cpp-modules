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
	std::time_t     get_timestamp() const { return (_creation_time); };
	std::string	get_name() const { return (_name); };
	~Contact();

private:
	std::string	_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
	std::time_t	_creation_time;
	bool		_is_valid_number(const std::string& number);
};


#endif
