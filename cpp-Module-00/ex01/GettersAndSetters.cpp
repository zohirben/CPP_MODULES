#include "Contact.hpp"

void Contact::setFirstName(const std::string &firstname)
{
    FirstName = firstname;
}
void Contact::setLastName(const std::string &lastname)
{
    LastName = lastname;
}
void Contact::setNickName(const std::string &nickname)
{
    NickName = nickname;
}
void Contact::setPhoneNumber(const std::string &number)
{
    PhoneNumber = number;
}
void Contact::setDarkestSecret(const std::string &secret)
{
    DarkestSecret = secret;
}

std::string Contact::getFirstName() const
{
    return FirstName;
}

std::string Contact::getLastName() const
{
    return LastName;
}

std::string Contact::getNickName() const
{
    return NickName;
}

std::string Contact::getPhoneNumber() const
{
    return PhoneNumber;
}

std::string Contact::getDarkestSecret() const
{
    return DarkestSecret;
}

void setData(const std::string &data, std::string *member)
{
    *member = data;
}