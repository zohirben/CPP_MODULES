#include "PhoneBook.hpp"

int main()
{
    PhoneBook phonebook;
    while (true)
    {
        std::string input;

        std::cout << "\033[1;32mADD\033[0m or \033[1;33mSEARCH\033[0m or \033[1;31mEXIT\033[0m: ";
        std::getline(std::cin, input);
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        if (input == "ADD")
        {
            phonebook.addContact();
        }
        if (input == "SEARCH")
        {
            phonebook.displayContacts();
        }
        if (input == "EXIT")
            exit(1);
    }
}