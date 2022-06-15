#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("Target", 72, 45), target("Target") {}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form(target, 72, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &other) : Form(other), target(other.target) {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &other) {
    if (this != &other)
        this->target = other.target;
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {}

// source https://www.cplusplus.com/reference/cstdlib/rand/
void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    Form::execute(executor);

    std::cout << "....Makes some drilling noises...." << std::endl;
    /* initialize random seed: */
    srand (time(NULL));
    /* generate secret number between 1 and 10: */
    int iSecret = rand() % 10 + 1;
    std::cout << "Random value: " << iSecret << std::endl;
    if (iSecret % 2 == 0)
        std::cout << this->getName() << " robotomized successfully" << std::endl;
    else
        std::cout << FRED << this->getName() << ":  robotomy failed" << NONE << std::endl;

}
