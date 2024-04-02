#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class AForm
{
private:
    std::string name;
    bool is_signed;
    const int signGrade;
    const int executeGrade;

    AForm();
public:
    AForm(const std::string &name, int signGrade, int executeGrade);
    AForm(const AForm &copy);
    AForm &operator=(const AForm &other);
    virtual ~AForm();

    // setters and getters
    std::string getName() const;
    bool getsigned() const;
    int getSignGrade() const;
    int getExecuteGrade() const;

    void setSignGrade(int signGrade);
    void setExecuteGrade(int executeGrade);

    // exception classes
    class GradeTooLowException : public std::exception {
        public:
            const char* what() const throw(){
                return "Grade is too low!";
            }
    };
    class GradeTooHighException : public std::exception {
        public:
            const char* what() const throw(){
                return "Grade is too High!";
            }
    };
    
    void beSigned(Bureaucrat &Bureaucrat);
    void execute(Bureaucrat const & executor) const;
    virtual void executeAction(Bureaucrat const & executor) const = 0;
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);