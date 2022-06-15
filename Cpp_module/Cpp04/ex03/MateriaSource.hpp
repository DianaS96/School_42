#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
    AMateria *inventory[4];
public:
    MateriaSource();
    MateriaSource(MateriaSource const & type);
    MateriaSource	&operator=(const MateriaSource &type);
    ~MateriaSource();

    virtual void learnMateria(AMateria*amateria);
    virtual AMateria* createMateria(std::string const & type);

};

#endif