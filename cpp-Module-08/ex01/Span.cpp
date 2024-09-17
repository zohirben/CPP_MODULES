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
    std::sort(SpanNums.begin(), SpanNums.end());

    int distance = INT_MAX;
    int temp = 0;
    for(unsigned long i = 0; i < SpanNums.size(); i++)
    {
        temp = SpanNums[i+1] - SpanNums[i];
        if (temp >= 0 && temp < distance)
        {
            distance = temp;
        }
    }
    if (distance == INT_MAX)
        return (-1);
    return (distance);
}

int Span::longestSpan()
{
    if (SpanNums.empty() || SpanNums.size() == 1)
        throw SpanNotFoundException();

    std::sort(SpanNums.begin(), SpanNums.end());
    return (SpanNums[SpanNums.size() - 1] - SpanNums[0]);
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