#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
}

void PhoneBook::addContact()
{
    static int CurrentIndex = 0;

    if (CurrentIndex == maxContacts)
        CurrentIndex = 0;

    Contact newContact;
    newContact.InitializeContact();
    ContactArray[CurrentIndex++] = newContact;
}

void PhoneBook::displayContacts()
{
    std::string input;
    int index;

    // Color codes for aesthetics
    const std::string headerColor = "\033[1;36m"; // Bold Cyan
    const std::string resetColor = "\033[0m";     // Reset color

    std::cout << headerColor << "------------------------------------------" << resetColor << std::endl;
    std::cout << headerColor << "| Index |First Name|Last Name |Nick Name |" << resetColor << std::endl;
    std::cout << headerColor << "------------------------------------------" << resetColor << std::endl;

    for (int i = 0; i < maxContacts; i++)
    {
        // Assuming DisplayList method uses color codes
        ContactArray[i].DisplayList(i);
    }

    std::cout << headerColor << "------------------------------------------" << resetColor << std::endl;

    do
    {
        std::cout << "Enter The Index: ";
        std::getline(std::cin, input);

        std::stringstream str(input);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        if (!(str >> index))
        {
            std::cout << "Please Enter A Valid Input" << std::endl;
        }
        else if (index < 0 || index >= maxContacts)
        {
            std::cout << "The Index You Entered Is Out Of Range!" << std::endl;
        }
        else
        {
            ContactArray[index].DisplayList(index);
        }
    } while (input.empty() || index < 0 || index >= maxContacts);
}
