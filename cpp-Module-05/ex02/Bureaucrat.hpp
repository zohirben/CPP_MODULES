#pragma once

#include <iostream>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
private:
    std::string name;
    int grade;

public:
    Bureaucrat();
    Bureaucrat(const std::string &name, int grade);
    Bureaucrat(const Bureaucrat &copy);
    Bureaucrat &operator=(const Bureaucrat &other);
    ~Bureaucrat();

    // setters and getters
    std::string getName() const;
    void setName(const std::string &name);
    int getGrade() const;
    void setGrade(int grade);
    void incrementGrade();
    void decrementGrade();

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

    void signForm(AForm &form);
    void executeForm(AForm const &form);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);