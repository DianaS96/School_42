#include "Bureaucrat.hpp"

void test_grade_too_low() {
    // try discovers throw operator and puts it to catch block
    try {
        Bureaucrat Cat("Cat", 1457389);
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void test_grade_too_high()
{
    try {
        Bureaucrat Cat("Cat", -1);
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void test_increment_grade() {
    try {
        Bureaucrat Cat("Cat", 3);
        try {
            Cat.incrementGraid();
            std::cout << Cat;
            Cat.incrementGraid();
            std::cout << Cat;
            Cat.incrementGraid();
            std::cout << Cat;
        }
        catch (std::exception &e)
        {
            std::cerr << FRED << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void    test_decrement_grade() {
    try {
        Bureaucrat Cat("Cat", 149);
        try {
            Cat.incrementGraid();
            std::cout << Cat;
            Cat.decrementGraid();
            std::cout << Cat;
            Cat.decrementGraid();
            std::cout << Cat;
            Cat.decrementGraid();
            std::cout << Cat;
        }
        catch (std::exception &e)
        {
            std::cerr << FRED << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e)
    {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}   

int main(void) {
    std::cout << FBLUE << "--------------TEST1(grade is too low)--------------" << NONE << std::endl;
    test_grade_too_low();

    std::cout << FBLUE << "--------------TEST2(grade is too high)--------------" << NONE << std::endl;
    test_grade_too_high();

    std::cout << FBLUE << "--------------TEST3(upgrading)--------------" << NONE << std::endl;
    test_increment_grade();

    std::cout << FBLUE << "--------------TEST4(decrementing)--------------" << NONE << std::endl;
    test_decrement_grade();

    return (0);
}