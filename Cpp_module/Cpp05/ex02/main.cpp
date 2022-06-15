#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    test_bureaucrat_ShrubberyCreationForm_not_signed() {
    try {
        Bureaucrat Cat("Cat", 10);
        std::cout << Cat;
        ShrubberyCreationForm List("Important list");
        std::cout << List;
        try {
            Cat.executeForm(List);
        }
        catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void    test_bureaucrat_ShrubberyCreationForm_LowExLvl() {
    try {
        Bureaucrat Cat("Cat", 138);
        std::cout << Cat;
        ShrubberyCreationForm List("Important list");
        std::cout << List;
        Cat.signForm(List);
        try {
            Cat.executeForm(List);
        }
        catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void    test_bureaucrat_ShrubberyCreationForm_Ok() {
    try {
        Bureaucrat Cat("Cat", 136);
        std::cout << Cat;
        ShrubberyCreationForm List("Important list");
        std::cout << List;
        Cat.signForm(List);
        try {
            Cat.executeForm(List);
        }
        catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void test_bureaucrat_RobotomyRequestForm_Ok() {
    try {
        Bureaucrat Dog("Dog", 44);
        std::cout << Dog;
        RobotomyRequestForm List("Robot list");
        std::cout << List;
        Dog.signForm(List);
        try {
            Dog.executeForm(List);
        }
        catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void test_bureaucrat_PresidentialPardonForm_Ok() {
    try {
        Bureaucrat Alpaca("Alpaca", 2);
        std::cout << Alpaca;
        PresidentialPardonForm List("Pardon_list");
        std::cout << List;
        Alpaca.signForm(List);
        try {
            Alpaca.executeForm(List);
        }
        catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

int main(void) {
    std::cout << FBLUE << "--------------TEST1(ShrubberyCreationForm_not_signed)--------------" << NONE << std::endl;
    test_bureaucrat_ShrubberyCreationForm_not_signed();

    std::cout << FBLUE << "--------------TEST2(ShrubberyCreationForm_LowExLvl)--------------" << NONE << std::endl;
    test_bureaucrat_ShrubberyCreationForm_LowExLvl();

    std::cout << FBLUE << "--------------TEST3(ShrubberyCreationForm_Ok)--------------" << NONE << std::endl;
    test_bureaucrat_ShrubberyCreationForm_Ok();
    
    std::cout << FBLUE << "--------------TEST4(RobotomyRequestForm_Ok)--------------" << NONE << std::endl;
    test_bureaucrat_RobotomyRequestForm_Ok();

    std::cout << FBLUE << "--------------TEST5(PresidentialPardonForm_Ok)--------------" << NONE << std::endl;
    test_bureaucrat_PresidentialPardonForm_Ok();

    return (0);
}
