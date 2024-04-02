#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    try
    {
        Bureaucrat slave("bob", 22);
        std::cout << "-------------------------------------\n";
        // Test ShrubberyCreationForm
        ShrubberyCreationForm shrubberyForm("home");
        slave.signForm(shrubberyForm);
        slave.executeForm(shrubberyForm);

        // Test RobotomyRequestForm
        RobotomyRequestForm robotomyForm("robot");
        slave.signForm(robotomyForm);
        slave.executeForm(robotomyForm);

        // Test PresidentialPardonForm
        PresidentialPardonForm pardonForm("criminal");
        slave.signForm(pardonForm);
        slave.executeForm(pardonForm);
    }
    catch (std::exception &e)
    {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}