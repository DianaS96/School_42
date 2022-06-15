#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

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

    //source: https://stackoverflow.com/questions/67873720/c-custom-exception-classes
    // https://stackoverflow.com/questions/22493294/what-is-the-meaning-of-this-header-virtual-const-char-what-const-throw
    // https://www.cplusplus.com/reference/exception/exception/
    // Overriding what() method that returns (const char*). 
    // The virtual keyword is optional
    // trow() -> No-throw guarantee: this member function never throws exceptions.
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