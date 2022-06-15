#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "Form.hpp"
#include <stdlib.h>     /* srand, rand */
#include <time.h>   
class RobotomyRequestForm : public Form
{
private:
    std::string target;
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(RobotomyRequestForm const &other);
	RobotomyRequestForm &operator=(RobotomyRequestForm const &other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const & executor) const;
};

#endif