#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(const std::string &name, int signGrade, int executeGrade) : name(name), is_signed(false), signGrade(signGrade), executeGrade(executeGrade)
{
    std::cout << "Form constructor called" << std::endl;
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
    std::cout << "Form Copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->is_signed = other.is_signed;
    }
    return *this;
}

Form::~Form()
{
    std::cout << "Destructor called" << std::endl;
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