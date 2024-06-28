#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain {
public:
    Brain ();
    Brain (const Brain &t_Brain);
    ~Brain ();
    Brain& operator = (const Brain &t_Brain);
	void setIdea(const std::string &idea, int index);
	std::string getIdea(int index) const;

private:
    	std::string m_ideas[100];

};

#endif
