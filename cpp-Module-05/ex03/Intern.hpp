#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Form.hpp"

class Intern
{
    private:
    public:
    Intern();
    Intern(const Intern &other);
    Intern &operator=(const Intern &other);
    ~Intern();

    Form *makeForm(std::string formname, std::string target);
};

typedef Form* (*FormCreator)(std::string);