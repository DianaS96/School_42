#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>
#include "ICharacter.hpp"

/*fonts color*/
# define FBLACK		"\033[0;30m"
# define FRED		"\033[0;31m"
# define FGREEN		"\033[0;32m"
# define FYELLOW	"\033[0;33m"
# define FBLUE		 "\033[0;34m"
# define FPURPLE	"\033[0;35m"
# define FCYAN		"\x1b[36m"
# define BRED		"\u001b[38;5;1m"

/*end color*/
# define NONE        "\033[0m"

class ICharacter;

class AMateria
{
protected:
    std::string type;
public:
    AMateria();
    AMateria(std::string const & type);
    AMateria(const AMateria &aMateria);
    AMateria	&operator=(const AMateria &aMateria);
    virtual ~AMateria();
    std::string const & getType() const; //Returns the materia type
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};

#endif