#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(ShrubberyCreationForm const &other);
	ShrubberyCreationForm &operator=(ShrubberyCreationForm const &other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const & executor) const;

    class FileCannnotBeOpened : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("ShrubberyCreationForm: can not open the file");
            };        
    };

};

#endif