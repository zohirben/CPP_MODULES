#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
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