#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
    Dog();
    Dog(std::string name);
	Dog(Dog const &other);
	Dog &operator=(Dog const &other);
    ~Dog();
    virtual void makeSound() const;
};

#endif