#pragma once

#include "Form.hpp"
#include <cstdlib>

class RobotomyRequestForm : public Form
{
private:
    std::string target;
    RobotomyRequestForm();
public:
    RobotomyRequestForm(std::string const &target);
    RobotomyRequestForm(RobotomyRequestForm &copy);
    ~RobotomyRequestForm();

    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

    void executeAction(Bureaucrat const & executor) const;
};