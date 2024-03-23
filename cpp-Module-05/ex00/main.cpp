#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat janitor("mohammed", 50);

    try
    {
        int btata;
        std::cin >> btata;
        janitor.setGrade(btata);
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
        // here we didnt make a catch if the grade is too high so if we tried to increment after grade 1 
        // it will abord the program
        try
        {
            lf.decrementGrade();
        }
        catch(const Bureaucrat::GradeTooLowException& e)
        {
            std::cerr << "Caught exception: " << e.what() << '\n';
        }
        
        
        std::cout << lf << std::endl;
    }
    return (0);
}