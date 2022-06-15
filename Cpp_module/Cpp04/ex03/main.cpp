#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"

int main()
{
    std::cout << FBLUE << "----------------Create MateriaSource--------------" << NONE << std::endl;
    IMateriaSource* src = new MateriaSource();
    std::cout << FBLUE << "----------------Learn Ice--------------" << NONE << std::endl;
    src->learnMateria(new Ice());
    std::cout << FBLUE << "----------------Learn Cure--------------" << NONE << std::endl;
    src->learnMateria(new Cure());
    std::cout << FBLUE << "----------------Create new character--------------" << NONE << std::endl;
    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout << FBLUE << "----------------Create new materia Ice--------------" << NONE << std::endl;
    tmp = src->createMateria("ice");
    std::cout << FBLUE << "----------------Equip materia Ice--------------" << NONE << std::endl;
    me->equip(tmp);
    std::cout << FBLUE << "----------------Create new materia cure--------------" << NONE << std::endl;
    tmp = src->createMateria("cure");
    std::cout << FBLUE << "----------------Equip materia cure--------------" << NONE << std::endl;
    me->equip(tmp);
    std::cout << FBLUE << "----------------Create bob--------------" << NONE << std::endl;
    ICharacter* bob = new Character("bob");
    std::cout << FBLUE << "----------------Bob uses ice and cure--------------" << NONE << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout << FBLUE << "----------------Unequip smth that you do not have--------------" << NONE << std::endl;
    me->unequip(2);
    std::cout << FBLUE << "----------------Unequip cure (ind 1)--------------" << NONE << std::endl;
    me->unequip(1);
    std::cout << FBLUE << "----------------Bob uses cure that he does not have--------------" << NONE << std::endl;
    me->use(1, *bob);
    std::cout << FBLUE << "----------------Destructure bob--------------" << NONE << std::endl;
    delete bob;
    std::cout << FBLUE << "----------------Destructure me--------------" << NONE << std::endl;
    delete me;
    std::cout << FBLUE << "----------------Destructure src--------------" << NONE << std::endl;
    delete src;
    return 0;
}