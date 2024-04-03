#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade) : name(name), is_signed(false), signGrade(signGrade), executeGrade(executeGrade)
{
    if (signGrade < 1)
        throw GradeTooHighException();
    else if (signGrade > 150)
        throw GradeTooLowException();
    if (executeGrade < 1)
        throw GradeTooHighException();
    else if (executeGrade > 150)
        throw GradeTooLowException();
}

Form::Form(const Form &copy) : name(copy.name), signGrade(copy.signGrade), executeGrade(copy.executeGrade)
{
}

Form &Form::operator=(const Form &other)
{
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

Form::~Form()
{
}

// setters and getters
std::string Form::getName() const
{
    return this->name;
}

bool Form::getsigned() const
{
    return this->is_signed;
}

int Form::getSignGrade() const
{
    return this->signGrade;
}

int Form::getExecuteGrade() const
{
    return this->executeGrade;
}

std::ostream &operator<<(std::ostream &os, const Form &obj)
{
    os << "Form: " << obj.getName()
       << "\nIs Signed: " << (obj.getsigned() ? "True" : "False") // output false or true instead of 0 or 1
       << "\nSign Grade: " << obj.getSignGrade()
       << "\nExecute Grade: " << obj.getExecuteGrade()
       << std::endl;
    return os;
}

void Form::beSigned(Bureaucrat &obj)
{
    if (obj.getGrade() <= this->signGrade)
        this->is_signed = true;
    else
        throw GradeTooLowException();
}

void Form::execute(Bureaucrat const & executor) const
{
    if (!getsigned())
        throw std::runtime_error("Form is not signed");
    if (executor.getGrade() > getExecuteGrade())
        throw GradeTooLowException();
    executeAction(executor);
}