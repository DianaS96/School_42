#include "Brain.hpp"

Brain::Brain() {
    std::cout << "Default Brain constructor called" << std::endl;
    int i = 0;

    while (i < 10)
    {
        ideas[i] = "I wanna eat ...";
        i++;
    }
}

Brain::Brain(Brain const &other) {
    std::cout << "Copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(Brain const &other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    return (*this);
}

Brain::~Brain() {
    std::cout << "Default Brain destructor called" << std::endl;
}

std::string Brain::getIdea(unsigned int i) {
    if (i < 100)
        return this->ideas[i];
    return (NULL);
}