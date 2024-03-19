#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat janitor("mohammed", 50);

    try
    {
        janitor.setGrade(-1290);
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Caught exception: " << e.what() << '\n';
    }

    std::cout << janitor << std::endl;

    {
        Bureaucrat lf;

        std::cout << lf << std::endl;
        lf.decrementGrade();
        std::cout << lf << std::endl;
    }
    return (0);
}