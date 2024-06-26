#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
{
    std::cout << "Default constructor called" << std::endl;
    this->setGrade(150);
    this->setName("ba3bot");
}

Bureaucrat::Bureaucrat(const std::string &name, int grade)
{
    std::cout << "Bureaucrat constructor called" << std::endl;
    this->setGrade(grade);
    this->setName(name);
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    this->name = copy.name;
    this->grade = copy.grade;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->name = other.name;
        this->grade = other.grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Destructor called" << std::endl;
}

// setters and getters
std::string Bureaucrat::getName() const
{
    return this->name;
}

void Bureaucrat::setName(const std::string &name)
{
    this->name = name;
}

int Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::setGrade(int grade)
{
    if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
    this->grade = grade;
}

void Bureaucrat::incrementGrade()
{
    try 
    {
        this->setGrade(grade - 1);
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Caught in 4k: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Caught in 4k: " << e.what() << std::endl;
    }
}

void Bureaucrat::decrementGrade()
{
    try 
    {
        this->setGrade(grade + 1);
    }
    catch (const Bureaucrat::GradeTooHighException &e)
    {
        std::cerr << "Caught in 4k: " << e.what() << std::endl;
    }
    catch (const Bureaucrat::GradeTooLowException &e)
    {
        std::cerr << "Caught in 4k: " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj)
{
    os << obj.getName() << ", bureaucrat grade " << obj.getGrade();
    return (os);
}

void Bureaucrat::signForm(AForm &form)
{
    try
    {
        form.beSigned(*this);
    }
    catch (const AForm::GradeTooLowException &e)
    {
        std::cerr << this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
        return;
    }
    std::cout << this->getName() << " signed " << form.getName() << std::endl;
}

void Bureaucrat::executeForm(AForm const &form)
{
    try
    {
        form.execute(*this);
    }
    catch(const std::exception& e)
    {
        std::cerr << this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
        return;
    }
    std::cout << getName() << " executed " << form.getName() << std::endl;
}