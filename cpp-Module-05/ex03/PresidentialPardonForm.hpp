#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
    std::string target;
    PresidentialPardonForm();
public:
    PresidentialPardonForm(std::string const &target);
    PresidentialPardonForm(PresidentialPardonForm &copy);
    ~PresidentialPardonForm();

    PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

    void executeAction(Bureaucrat const & executor) const;
};