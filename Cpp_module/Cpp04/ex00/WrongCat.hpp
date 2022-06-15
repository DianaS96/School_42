#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
    WrongCat();
    WrongCat(std::string name);
	WrongCat(WrongCat const &other);
	WrongCat &operator=(WrongCat const &other);
    ~WrongCat();
    void makeSound() const;
};

#endif