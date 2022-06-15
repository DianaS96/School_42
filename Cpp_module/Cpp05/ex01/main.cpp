#include "Bureaucrat.hpp"

void    test_form() {
    try {
        Form Lol("Important list", 177, 89);
        std::cout << Lol;
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
    try {
        Form Lol("Important list", 77, -99);
        std::cout << Lol;
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void test_bureaucrat_form_wrong() {
    try {
        Bureaucrat Cat("Cat", 10);
        std::cout << Cat;
        Form List("Important list", 9, 10);
        std::cout << List;
        try {
            Cat.signForm(List);
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

void    test_bureaucrat_form_norm() {
    try {
        Bureaucrat Cat("Cat", 10);
        std::cout << Cat;
        Form List("Important list", 9, 10);
        std::cout << List;
        Cat.incrementGraid();
        std::cout << Cat;
        try {
            Cat.signForm(List);
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
    std::cout << FBLUE << "--------------TEST1(bad Form)--------------" << NONE << std::endl;
    test_form();

    std::cout << FBLUE << "--------------TEST2(wrong lvl)--------------" << NONE << std::endl;
    test_bureaucrat_form_wrong();

    std::cout << FBLUE << "--------------TEST3(Ok)--------------" << NONE << std::endl;
    test_bureaucrat_form_norm();

    return (0);
}
