#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
    const std::string name;
    bool sign;
    const int grade_sign;
    const int grade_ex;

public:
    Form();
    Form(std::string name, int grade_sign, int grade_ex);
    Form(Form const &other);
	Form &operator=(Form const &other);
    virtual ~Form();

    void beSigned(Bureaucrat const &bureaucrat);
    virtual void execute(Bureaucrat const & executor) const = 0;

    std::string getName() const;    
    bool getIsSigned() const;    
    int getGradeSign() const;
    int getGradeExec() const;

    class GradeTooLowException : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("Bureaucrat's grade is too low");
            };        
    };

    class GradeTooHighException : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("Bureaucrat'sgrade is too high");
            };        
    };

    class FormIsNotSigned : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("Form is not signed");
            };        
    };
};

std::ostream &operator<<(std::ostream &object, Form const &form);

#endif