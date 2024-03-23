#include "Bureaucrat.hpp"

int main()
{
    Form wati9a("lifetime job contract", 50, 100);
    std::cout << wati9a;
    std::cout << "-------------------------------------\n";
    Bureaucrat slave("bob", 66);
    slave.signForm(wati9a);

    return (0);
}