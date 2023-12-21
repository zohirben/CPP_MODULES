#pragma once

#include <iostream>
#include <iomanip>
#include <sstream>
#include "Contact.hpp"

class PhoneBook
{
private:
    static const int maxContacts = 8;
    Contact ContactArray[maxContacts];
public:
    PhoneBook();

    void addContact();
    void displayContacts(); 

}; 
