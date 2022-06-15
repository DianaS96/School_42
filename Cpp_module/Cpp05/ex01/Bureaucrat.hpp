#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

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

class Form;

class Bureaucrat
{
private:
    const std::string name;
    int grade;
public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(Bureaucrat const &other);
	Bureaucrat &operator=(Bureaucrat const &other);
    ~Bureaucrat();

    int getGrade() const;
    std::string getName() const;

    void incrementGraid();
    void decrementGraid();
    void signForm(Form &form);

    //source: https://stackoverflow.com/questions/67873720/c-custom-exception-classes
    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("Bureaucrat: grade is too low, min lvl is 150");
            };        
    };
    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("Bureaucrat: grade is too high, max lvl is 1");
            };        
    };

};
std::ostream &operator<<(std::ostream &object, Bureaucrat const &bureaucrat);

#endif