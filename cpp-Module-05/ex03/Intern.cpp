#include "Intern.hpp"
Intern::Intern() {}

Intern::Intern(const Intern &other)
{
    *this = other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern() {}

Form *Intern::makeForm(std::string formname, std::string target)
{
    std::string formNames[] = {"shrubbery creation",
                               "robotomy request",
                               "presidential pardon"};

    for (int i = 0; i < 3; i++)
    {
        if (formNames[i] == formname)
        {
            std::cout << "Intern creates " << formname << std::endl;
            switch (i)
            {
            case 0:
                return new ShrubberyCreationForm(target);
            case 1:
                return new RobotomyRequestForm(target);
            case 2:
                return new PresidentialPardonForm(target);
            }
        }
    }

    std::cout << "Error: Invalid form name" << std::endl;
    return NULL;
}
