#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>
#include <cctype>
#include <string>
#include <cstdio>
#include <sstream>

class Utils {

public:
	Utils();
	Utils(const Utils &t_utils);
	Utils & operator = (const Utils &t_utils);
	static std::string  format_column(const std::string& t_str);
	static std::string  get_input(const std::string&);
	static void         clear_stdin(std::istream& t_in);
	static std::string  to_str(size_t t_nbr);
	~Utils();

private:

};

#endif
