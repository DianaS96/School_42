#include "Converter.hpp"

void ft_print_char(double num, int input)
{
    std::cout << "char: ";
    if (input || num < 0 || num > 127)
        std::cout << "impossible" << std::endl;
    else if (!std::isprint(num))
        std::cout << "Non displayable" << std::endl;
    else
        std::cout << static_cast<char>(num) << std::endl;
}

void ft_print_int(double num, int input)
{
    std::cout << "int: ";
    if (input)
        std::cout << "impossible" << std::endl;
    else if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
        std::cout << "num is out of range" << std::endl;
    else
        std::cout << static_cast<int>(num) << std::endl;
}

void ft_print_float(double num, int input)
{
    std::cout.precision(1);
    std::cout << "float: ";
    if (input && !std::isnan(num) && !std::isinf(num))
        std::cout << "impossible" << std::endl;
    else if ((num > std::numeric_limits<float>::max() || num < std::numeric_limits<float>::min()) && !std::isinf(num))
        std::cout << "num is out of range" << std::endl;
    else
    {
        std::cout << std::fixed << static_cast<float>(num);
        std::cout << "f" << std::endl;
    }
}

void ft_print_double(double num, int input, bool overflow, bool underflow)
{
    std::cout.precision(1);
    std::cout << "double: ";
    if (input && !std::isnan(num) && !std::isinf(num))
        std::cout << "impossible" << std::endl;
    else if (overflow || underflow)
        std::cout << "num is out of range" << std::endl;
    else
        std::cout << std::fixed << static_cast<double>(num) << std::endl;
}

int ft_check_input(std::string str) {
    int i = 0;
    bool has_dot = false;
    bool float_point = false;

    if (str[i] && !str[i + 1])
        return (0);
    if (str[i] == '-' || str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
        i++;
    if (str[i] == '.')
    {
        has_dot = true;
        i++;
        while (str[i] >= '0' && str[i] <= '9')
        {
            float_point = true;
            i++;
        }
    }
    if (str[i] == 'f' && !str[i + 1] && has_dot && float_point)
        return (0);
    else if (!str[i])
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    int input;
    double num;
    bool overflow = false;
    bool underflow = false;
    std::string str;
    char *e = NULL;
    if (argc != 2)
    {
        std::cout << FRED << "Invalid number of arguments." << NONE << std::endl;
        std::cout << FRED << "Usage: ./conversion [str]." << NONE << std::endl;
        return (1); 
    }
    str = argv[1];
    input = ft_check_input(str);
    if (str.length() == 1 && !std::isdigit(str[0]))
        num = static_cast<double>(str[0]);
    else
    {
        num = std::strtod(argv[1], &e);
        if ((num == HUGE_VAL || -num == HUGE_VAL) && errno == ERANGE) 
            overflow = true; 
        if (num == 0 && errno == ERANGE)
            underflow = true;
    }
    ft_print_char(num, input);
    ft_print_int(num, input);
    ft_print_float(num, input);
    ft_print_double(num, input, overflow, underflow);
    return (0); 
}