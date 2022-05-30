#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2)
    {
        std::cout << FRED << "Usage:  ./harlFilter [level]" << NONE << std::endl;
        std::cout << FRED << "Allowed levels: DEBUG/INFO/WARNING/ERROR" << NONE << std::endl;
        return (1);
    }
    harl.complain(argv[1]);
    return (0);
}