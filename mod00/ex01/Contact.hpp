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
	Contact(const Contact &t_contact);
	Contact & operator = (const Contact &t_contact);
	Contact&		set_contact();
	void			print_contact(size_t t_idx);
	void			print_contact();
	std::time_t     get_timestamp() const { return (m_creation_time); };
	std::string	get_name() const { return (m_name); };
	~Contact();

private:
	std::string	m_name;
	std::string	m_last_name;
	std::string	m_nickname;
	std::string	m_phone_number;
	std::string	m_darkest_secret;
	std::time_t	m_creation_time;
	bool		m_is_valid_number(const std::string& t_number);
};


#endif
