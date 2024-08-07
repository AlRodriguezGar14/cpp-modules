#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>
#include <sstream>

class Brain {
public:
    Brain ();
    Brain (const Brain &t_Brain);
    ~Brain ();
    Brain& operator = (const Brain &t_Brain);
	void setIdea(const std::string &t_idea, int t_index);
	std::string getIdea(int t_index) const;

private:
    	std::string m_ideas[100];

};

#endif
