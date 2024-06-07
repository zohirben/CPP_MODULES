#include "Span.hpp"

int main()
{
    Span sp(6);

    try
    {
        sp.addNumber(3);
        sp.addNumber(2);
        sp.addNumber(5);
        sp.addNumber(10);
        sp.addNumber(30);
        sp.addNumber(9);
    }
    catch (Span::SpanFullException &e)
    {
        std::cerr << "exception: " << e.what() << std::endl;
    }

    // i seperated the exception catch to not stop the program early.
    try
    {
        std::cout << "shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "lognest span: " << sp.longestSpan() << std::endl;
    }
    catch (Span::SpanNotFoundException &e)
    {
        std::cerr << "exception: " << e.what() << '\n';
    }

    std::cout << "--------------------------------------------------\n";
    // created up to N random numbers using rand function
    {
        unsigned int N = 30000;
        std::cout << "Span Length: " << N << std::endl;
        Span sp(N);

        sp.FillSpan();

        std::cout << "shortest: " << sp.shortestSpan() << std::endl;
        std::cout << "lognest: " << sp.longestSpan() << std::endl;
    }

    return (0);
}