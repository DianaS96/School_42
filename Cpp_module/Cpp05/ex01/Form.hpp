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
    ~Form();

    void beSigned(Bureaucrat const &bureaucrat);

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
};

std::ostream &operator<<(std::ostream &object, Form const &form);

#endif