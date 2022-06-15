#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

/*fonts color*/
# define FBLACK		"\033[0;30m"
# define FRED		"\033[0;31m"
# define FGREEN		"\033[0;32m"
# define FYELLOW	"\033[0;33m"
# define FBLUE		 "\033[0;34m"
# define FPURPLE	"\033[0;35m"
# define FCYAN		"\x1b[36m"

/*end color*/
# define NONE        "\033[0m"

class Animal
{
protected:
    std::string type;
public:
    Animal();
    Animal(std::string type);
	Animal(Animal const &other);
	Animal &operator=(Animal const &other);
    virtual ~Animal();
    virtual void makeSound() const = 0;
    std::string getType() const;
};

#endif