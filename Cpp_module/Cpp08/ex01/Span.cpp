#include "Span.hpp"

bool myfunction (int i,int j) { return (i<j); }

Span::Span() : N(0) {
}

Span::Span(int size) : N(size) {
}

Span::Span(Span const &span) {
    if (this != &span)
        *this = span;
}

Span &Span::operator=(Span const &span) {
    N = span.N;
    vec = span.vec;
    return (*this);
}

void Span::addNumber(int num) {
    if (vec.size() >= N)
        throw Span::SpanIsAlreadyFilled();
    vec.push_back(num);
}

void Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (begin >= end)
        throw Span::InvalidRange();
    while (begin < end) {
        if (vec.size() >= N)
            throw Span::SpanIsAlreadyFilled();
        this->addNumber(*begin);
        begin++;
    }
}

int Span::shortestSpan() {
    if (!vec.size())
        throw Span::NoNumbersFound();
    if (vec.size() == 1)
        throw Span::JusOneNumberFound();
    std::sort (vec.begin(), vec.end(), myfunction);
    int shortest = vec[1] - vec[0];
    for (std::vector<int>::iterator it = vec.begin(); it + 1 != vec.end(); ++it) {
        if ((*(it + 1)) - (*it) < shortest)
            shortest = (*(it + 1)) - (*it);
    }
    return (shortest);
}

int Span::longestSpan() {
    if (!vec.size())
        throw Span::NoNumbersFound();
    if (vec.size() == 1)
        throw Span::JusOneNumberFound();
    std::sort (vec.begin(), vec.end(), myfunction);
    return((*(vec.end() - 1)) - (*vec.begin()));
}

void Span::printSpan() {
    std::sort (vec.begin(), vec.end(), myfunction);
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
        std::cout << *it << " | ";
    }
    std::cout << std::endl;
}

std::vector<int> Span::getVector() {
    return (vec);
}

Span::~Span()
{
}