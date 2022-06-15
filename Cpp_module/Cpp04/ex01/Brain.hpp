#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
	Brain(Brain const &other);
	Brain &operator=(Brain const &other);
    ~Brain();
    std::string getIdea(unsigned int i);
};

#endif