#include "Contact.hpp"

Contact::Contact()
{
}

void Contact::InitializeContact()
{
    std::string buffer;

    do
    {
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        std::cout << "Enter First Name: ";
        std::getline(std::cin, buffer);
    } while (buffer.empty());
    setFirstName(buffer);

    do
    {
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, buffer);

    } while (buffer.empty());
    setLastName(buffer);

    do
    {
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        std::cout << "Enter Nick Name: ";
        std::getline(std::cin, buffer);
    } while (buffer.empty());
    setNickName(buffer);

    do
    {
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, buffer);
    } while (buffer.empty());
    setPhoneNumber(buffer);

    do
    {
        if (std::cin.eof())
        {
            std::cout << std::endl;
            exit(0);
        }
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, buffer);
    } while (buffer.empty());
    setDarkestSecret(buffer);
}

void Contact::DisplayList(int index)
{
    if (!(getFirstName()[0]))
        return;
    std::cout << "|   " << index << "   ";
    displayColumn(getFirstName());
    displayColumn(getLastName());
    displayColumn(getNickName());
    std::cout << "|" << std::endl;
}

void Contact::displayColumn(std::string str)
{
    if (str.length() <= 10)
        std::cout << "|" << std::right << std::setw(10) << str;
    else
        std::cout << "|" << std::setw(9) << str.substr(0, 9) << ".";
}

void Contact::DisplayContacts()
{
    std::cout << "Contact Information:" << std::endl;
    displayMember("First Name", getFirstName());
    displayMember("Last Name", getLastName());
    displayMember("Nick Name", getNickName());
    displayMember("Phone Number", getPhoneNumber());
    displayMember("Darkest Secret", getDarkestSecret());
}
void displayMember(const std::string &label, const std::string &value)
{
    std::cout << label << ": " << value << std::endl;
}
