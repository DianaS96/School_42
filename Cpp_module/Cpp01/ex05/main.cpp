#include "Harl.hpp"

int main(void)
{
    Harl harl;
    std::string input;
    
    std::cout << "Allowed options: DEBUG/INFO/WARNING/ERROR" << std::endl;
    std::cout << "Enter option: ";
    getline(std::cin, input);
    harl.complain(input);
    return (0);
}