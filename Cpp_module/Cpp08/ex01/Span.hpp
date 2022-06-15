#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <exception>
#include <time.h>
#include <stdlib.h>

/*fonts color*/
# define FBLACK		"\033[0;30m"
# define FRED		"\033[0;31m"
# define FGREEN		"\033[0;32m"
# define FYELLOW	"\033[0;33m"
# define FBLUE		 "\033[0;34m"
# define FPURPLE	"\033[0;35m"
# define FCYAN		"\x1b[36m"

/*end color*/
# define NONE        "\033[0m"

class Span
{
private:
    unsigned int N;
    std::vector<int> vec;

public:
    Span();
    Span(int size);
    Span(Span const &span);
    ~Span();

	Span &operator=(Span const &span);

    void addNumber(int num);
    void addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);

    int shortestSpan();
    int longestSpan();
    void printSpan();
    std::vector<int> getVector();

    class NoNumbersFound : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("There are no elements stored!");
        }
    };

    class JusOneNumberFound : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("There is only one element stored!");
        }
    };

    class SpanIsAlreadyFilled : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("There is no space for another element!");
        }
    };

    class InvalidRange : public std::exception
    {
        public:
            virtual const char* what() const throw() {
                return ("Begin value should be less than end value!");
        }
    };

};

#endif