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
	Utils(const Utils &utils);
	Utils & operator = (const Utils &utils);
	static std::string format_column(const std::string& str);
	static std::string get_input(const std::string&);
	static void		clear_stdin(std::istream& in);
	static std::string to_str(size_t nbr);
	~Utils();

private:

};

#endif
