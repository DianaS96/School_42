#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("Anonynous"), grade(150) {
    std::cout << "Default Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {
    if (grade < 0)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else
        std::cout << "Bureaucrat constructor called" << std::endl;
}

 Bureaucrat::Bureaucrat(Bureaucrat const &other) {
     *this = other;
 }

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &other) {
    if (this != &other)
        this->grade = other.getGrade();
    return (*this);
}

int Bureaucrat::getGrade() const {
    return (grade);
}

std::string  Bureaucrat::getName() const {
    return (name);
}

void Bureaucrat::incrementGraid() {
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade -= 1;
}

void Bureaucrat::decrementGraid() {
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade += 1;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Default Bureaucrat destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &object, Bureaucrat const &bureaucrat) {
    object << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return (object);
}

void Bureaucrat::signForm(Form &form) {
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << FRED << this->getName() << " could not sign " << form.getName() << " because " << e.what() << NONE << std::endl;
    }
}

void Bureaucrat::executeForm(Form const & form) {
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << this->getName() << " could not execute " << form.getName() << " because " << e.what() << NONE << std::endl;
    }
}