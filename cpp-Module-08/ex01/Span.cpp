#include "Span.hpp"

Span::Span(unsigned int N)
{
    MaxNums = N;
}
Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    if (this != &other)
    {
        this->SpanNums = other.SpanNums;
        this->MaxNums = other.MaxNums;
    }
    return *this;
}
Span::~Span()
{
}

void Span::addNumber(int x)
{
    if (SpanNums.size() < MaxNums)
    {
        SpanNums.push_back(x);
    }
    else
        throw SpanFullException();
}

int Span::shortestSpan()
{
    if (SpanNums.empty() || SpanNums.size() == 1)
        throw SpanNotFoundException();
    // std::sort(SpanNums.begin(), SpanNums.end());
    // return SpanNums.front();
    // sorting everytime you enter a function is a heavy performance on the program.

    // simpler, eaiser, faster :D
    std::vector<int>::iterator it = std::min_element(SpanNums.begin(), SpanNums.end());
    return *it;
}

int Span::longestSpan()
{
    if (SpanNums.empty() || SpanNums.size() == 1)
        throw SpanNotFoundException();

    std::vector<int>::iterator it = std::max_element(SpanNums.begin(), SpanNums.end());
    return *it;
}

// fill the whole container to its max with random numbers
void    Span::FillSpan()
{
    std::srand(std::time(0));
    if (SpanNums.size() < MaxNums)
    {
        std::vector<int> temp(MaxNums - SpanNums.size());
        std::generate(temp.begin(), temp.end(), std::rand);
        SpanNums.insert(SpanNums.end(), temp.begin(), temp.end());
    }
    std::cout << "current full size: " << SpanNums.size() << std::endl;
}