#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> 
#include <ctime>

class Span
{
private:
    std::vector<int> SpanNums;
    unsigned int MaxNums;
    Span();

public:
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    class SpanFullException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "Span is already full";
        }
    };
    class SpanNotFoundException : public std::exception
    {
    public:
        const char *what() const throw()
        {
            return "No Span found";
        }
    };

    void    addNumber(int x);
    int    shortestSpan();
    int    longestSpan();
};