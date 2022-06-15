#include "Span.hpp"

void ft_test_add_to_full_span(int size) {
    Span span(size);
    srand (time(NULL));
    for (int i = 0; i <= size; i++)
    {
        try {
            span.addNumber(rand() % 1000 + 1);
        }
        catch (std::exception &e) {
            std::cerr << FRED << e.what() << NONE << std::endl;
        }
    }
    span.printSpan();
    std::cout << "Shortest span: " << span.shortestSpan() << std::endl;
    std::cout << "Longest span: " << span.longestSpan() << std::endl;
}

void ft_test_empty_span(int size) {
    Span span(size);
    srand (time(NULL));
    span.printSpan();
    try {
        std::cout << "Shortest span: " << span.shortestSpan() << std::endl;    
    }
    catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
    span.addNumber(rand() % 1000 + 1);
    span.printSpan();
    try {
        std::cout << "Longest span: " << span.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

void ft_test_from_subject() {
    Span sp = Span(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void ft_fill_range() {
    std::vector<int> vec;
    for (int i = 0; i < 20000; i++)
        vec.push_back(i);
    Span sp(20000);
    srand (time(NULL));
    sp.addNumber(vec.begin(), vec.end());
    std::cout << "Number of elements: " << sp.getVector().size() << std::endl;
    // sp.printSpan();
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;
}

void ft_fill_invalid_range() {
    std::vector<int> vec;
    for (int i = 0; i < 20000; i++)
        vec.push_back(i);
    Span sp(20000);
    try {
        sp.addNumber(vec.end(), vec.begin());
        std::cout << "Number of elements: " << sp.getVector().size() << std::endl;
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch (std::exception &e) {
        std::cerr << FRED << e.what() << NONE << std::endl;
    }
}

int main(void) {
    std::cout << FPURPLE << "----------------Test0(SUBJECT)----------------" << NONE << std::endl;
    ft_test_from_subject();

    std::cout << FPURPLE << "----------------Test1(Add to full span)----------------" << NONE << std::endl;
    ft_test_add_to_full_span(10);

    std::cout << FPURPLE << "----------------Test2(Span has 1 or 0 elements)----------------" << NONE << std::endl;
    ft_test_empty_span(5);

    std::cout << FPURPLE << "----------------Test3(Fill range)----------------" << NONE << std::endl;
    ft_fill_range();

    std::cout << FPURPLE << "----------------Test4(Fill invalid range)----------------" << NONE << std::endl;
    ft_fill_invalid_range();
    return (0);
}