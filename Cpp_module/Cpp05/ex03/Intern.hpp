#ifndef INTERN_HPP
#define INTERN_HPP

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
public:
    Intern();
    Intern(Intern const &other);
	Intern &operator=(Intern const &other);
    ~Intern();

    Form *makeForm(std::string form_name, std::string const &target);

    class FormDoesNotExist : public std::exception
    {
        public:
             virtual const char* what() const throw() {
                return ("The Form does not exist!");
            };
    };
};

#endif