#pragma once

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
private:
    std::string name;
    bool is_signed;
    const int signGrade;
    const int executeGrade;

    Form();
public:
    Form(const std::string &name, int signGrade, int executeGrade);
    Form(const Form &copy);
    Form &operator=(const Form &other);
    ~Form();

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
};

std::ostream &operator<<(std::ostream &os, const Form &obj);