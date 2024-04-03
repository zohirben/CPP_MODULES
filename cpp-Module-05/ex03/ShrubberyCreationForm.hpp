#pragma once

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public Form
{
private:
    std::string target;
    ShrubberyCreationForm();
public:
    ShrubberyCreationForm(std::string const &target);
    ShrubberyCreationForm(ShrubberyCreationForm &copy);
    ~ShrubberyCreationForm();

    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

    void executeAction(Bureaucrat const & executor) const;
};