#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "I cannot believe adding extra bacon costs more money." << std::endl << \
    "You did not put enough bacon in my burger!" << std::endl << \
    "If you did, I would not be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl << \
    "I have been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error() {
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int     i = 0;
    // method points to a member of Harl that takes nothing
    typedef void (Harl::*method)();
    // array of pointers-to-member-functions
    method methods[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string cases[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

    while (i < 4)
    {
        if (level == cases[i])
            break ;
        i++;
    }
    switch (i)
    {
        case 0:
            (this->*methods[0])();
            break ;
        case 1:
            (this->*methods[1])();
            break ;
        case 2:
            (this->*methods[2])();
            break ;
        case 3:
            (this->*methods[3])();
            break ;
        default:
            std::cout << FRED << "Wrong option. Allowed options: DEBUG/INFO/WARNING/ERROR" << NONE << std::endl;
            break ;
    }
}
