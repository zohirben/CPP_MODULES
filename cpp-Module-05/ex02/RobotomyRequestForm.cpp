#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : AForm("Robot Request Form", 75, 45), target(target) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy) : AForm(copy), target(copy.target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    (void) other;
    return *this;
}

void RobotomyRequestForm::executeAction(Bureaucrat const & executor) const
{
    (void) executor;
    std::cout << "Drilling noises..." << std::endl;
    if (rand() <= RAND_MAX / 2) {
        std::cout << this->target << " has been robotomized successfully." << std::endl;
    } else {
        std::cout << "Robotomy of " << this->target << " failed." << std::endl;
    }
}