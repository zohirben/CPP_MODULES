#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name, int signGrade, int executeGrade) : name(name), is_signed(false), signGrade(signGrade), executeGrade(executeGrade)
{
    std::cout << "AForm constructor called" << std::endl;
    if (signGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
    if (executeGrade < 1)
        throw GradeTooHighException();
    else if (executeGrade > 150)
        throw GradeTooLowException();
}

AForm::AForm(const AForm &copy) : name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
}

AForm &AForm::operator=(const AForm &other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

AForm::~AForm()
{
}

// setters and getters
std::string AForm::getName() const
{
    return this->name;
}

bool AForm::getsigned() const
{
    return this->is_signed;
}

int AForm::getSignGrade() const
{
    return this->signGrade;
}

int AForm::getExecuteGrade() const
{
    return this->executeGrade;
}

std::ostream &operator<<(std::ostream &os, const AForm &obj)
{
    os << "AForm: " << obj.getName()
       << "\nIs Signed: " << (obj.getsigned() ? "True" : "False") // output false or true instead of 0 or 1
       << "\nSign Grade: " << obj.getSignGrade()
       << "\nExecute Grade: " << obj.getExecuteGrade()
       << std::endl;
    return os;
}

void AForm::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() <= this->signGrade)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

void AForm::execute(Bureaucrat const & executor) const
{
    if (!getsigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    executeAction(executor);
}