#include <iostream>
#include <string>

int main(void)
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    // print memory address of the string variable
    std::cout << &str << std::endl;
    // print memory address held by stringPTR
    std::cout << stringPTR << std::endl;
    // print memory address held by stringREF
    std::cout << &stringREF << std::endl;

    // print value of the string variable.
    std::cout << str << std::endl;
    // print value pointed to by stringPTR.
    std::cout << *stringPTR << std::endl;
    // print value pointed to by stringREF.
    std::cout << stringREF << std::endl;
    
    return (0);
}