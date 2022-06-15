#include "Form.hpp"

Form::Form() : name("None"), sign(false), grade_sign(150), grade_ex(150) {
    return ;
}

Form::Form(std::string name, int grade_sign, int grade_ex) : name(name), 
sign(false), grade_sign(grade_sign), grade_ex(grade_ex) {
    if (grade_ex < 0 || grade_sign < 0)
        throw Form::GradeTooHighException();
    if (grade_ex > 150 || grade_sign > 150)
        throw Form::GradeTooLowException();
    return ;
}

Form::Form(Form const &other) : name(other.getName()), sign(other.getIsSigned()), 
grade_sign(other.getGradeSign()), grade_ex(other.getGradeExec()) {
}

Form &Form::operator=(Form const &other) {
    (void)other;
    return (*this);
}

std::string Form::getName() const {
    return (this->name);
}

bool Form::getIsSigned() const {
    return (this->sign);
}

int Form::getGradeExec() const {
    return (this->grade_ex);
}

int Form::getGradeSign() const {
    return (this->grade_sign);
}

std::ostream &operator<<(std::ostream &object, Form const &form) {
    object << form.getName() << \
    "; signed: " << form.getIsSigned() << \
    "; grade required to sign: " << form.getGradeSign() << \
    "; grade required to execute: " << form.getGradeExec() << std::endl;
    return (object);
}

Form::~Form() {}

void Form::beSigned(Bureaucrat const &bureaucrat) {
    if (this->getGradeSign() < bureaucrat.getGrade())
        throw Form::GradeTooLowException();
    else
        this->sign = true;
}

void Form::execute(Bureaucrat const & executor) const {
    if (!this->getIsSigned())
        throw Form::FormIsNotSigned();
    if (this->getGradeExec() < executor.getGrade())
        throw Form::GradeTooLowException();
}
