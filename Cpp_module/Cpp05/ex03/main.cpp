#include "Bureaucrat.hpp"
#include "Intern.hpp"

void test_Intern_Bad_Form() {
    try {
        std::string form_name = "BadForm";
        std::string form_target = "BadFormName";
        Bureaucrat Alpaca("Alpaca", 2);
        std::cout << Alpaca;
        Intern Cat;
        Form *List;
        try {
            List = Cat.makeForm(form_name, form_target);
            std::cout << List;
            Alpaca.signForm(*List);
            try {
                Alpaca.executeForm(*List);
                delete List;
            }
            catch (std::exception &e) {
            std::cerr << FRED << e.what() << NONE << std::endl;
            }
        }
        catch (std::exception &e) {
            std::cerr << FRED << form_name << ": " << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void test_Intern_Good_Form() {
    try {
        std::string form_name = "ShrubberyCreationForm";
        std::string form_target = "LolKekCheburek";
        Bureaucrat Alpaca("Alpaca", 2);
        std::cout << Alpaca;
        Intern Cat;
        Form *List;
        try {
            List = Cat.makeForm(form_name, form_target);
            std::cout << *List;
            Alpaca.signForm(*List);
            try {
                Alpaca.executeForm(*List);
                delete List;
            }
            catch (std::exception &e) {
            std::cerr << FRED << e.what() << NONE << std::endl;
            }
        }
        catch (std::exception &e) {
            std::cerr << FRED << form_name << ": " << e.what() << NONE << std::endl;
        }
    }
    catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

int main(void) {
    std::cout << FBLUE << "--------------TEST1(Intern_Bad_Form)--------------" << NONE << std::endl;
    test_Intern_Bad_Form();

    std::cout << FBLUE << "--------------TEST1(Intern_ShrubberyCreationForm)--------------" << NONE << std::endl;
    test_Intern_Good_Form();

    return (0);
}
