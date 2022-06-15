#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("Target", 25, 5), target("Target") {}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form(target, 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &other) : Form(other), target(other.target) {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &other) {
    if (this != &other)
        this->target = other.target;
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {}


void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    Form::execute(executor);

    std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
