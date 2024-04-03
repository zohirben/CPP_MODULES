#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string const &target) : Form("Presedintal Pardon Form", 25, 5), target(target) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy) : Form(copy), target(copy.target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    (void) other;
    return *this;
}

void PresidentialPardonForm::executeAction(Bureaucrat const & executor) const
{
    (void) executor;
    std::cout << this->target << "  has been pardoned by Zaphod Beeblebrox." << std::endl;
}