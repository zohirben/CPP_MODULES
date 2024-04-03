#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{

    {
        Intern someRandomIntern;
        Form *rrf;
        // available forms
        // shrubbery creation
        // robotomy request
        // presidential pardon
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf != NULL)
        {
            std::cout << "Created a form with name: " << rrf->getName() << std::endl;
        }
        delete rrf;
    }

    return 0;
}