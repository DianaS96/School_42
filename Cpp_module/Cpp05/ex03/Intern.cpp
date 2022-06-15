#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(Intern const &other) {
    *this = other;
}

Intern &Intern::operator=(Intern const &other) {
    (void)other;
    return (*this);
}

Form *Intern::makeForm(std::string form_name, std::string const &target) {
    int form_num = -1;
    int i = 0;
    std::string targets[3] = {"ShrubberyCreationForm", "PresidentialPardonForm", "RobotomyRequestForm"};
    Form *tmp[3] = {new ShrubberyCreationForm(target),\
                    new PresidentialPardonForm(target),\
                    new RobotomyRequestForm(target)};
    for (i = 0; i < 3; i++)
    {
        if (form_name == targets[i])
        {
            form_num = i;
            break ;
        }
    }
    if (form_num == -1)
    {
        for (i = 0; i < 3; i++)
            delete tmp[i];
        throw Intern::FormDoesNotExist();
    }
    else
    {
        std::cout << "Intern creates " << form_name << " named " << target << std::endl;
        if (i == 0)
        {
            delete tmp[1];
            delete tmp[2];
        }
        else if (i == 1)
        {
            delete tmp[0];
            delete tmp[2];
        }
        else
        {
            delete tmp[0];
            delete tmp[1];
        }
        return (tmp[i]);
    }
}