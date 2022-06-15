#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
    std::string name;
public:
    WrongAnimal();
    WrongAnimal(std::string name);
	WrongAnimal(WrongAnimal const &other);
	WrongAnimal &operator=(WrongAnimal const &other);
    virtual ~WrongAnimal();
    void makeSound() const;
    std::string getType() const;
};

#endif