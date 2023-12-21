#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

class Contact
{
private:
    std::string FirstName;
    std::string LastName;
    std::string NickName;
    std::string PhoneNumber;
    std::string DarkestSecret;

public:
    Contact();

    void InitializeContact();
    void DisplayList(int index);
    void displayColumn(std::string str);
    void DisplayContacts();
    void setFirstName(const std::string &firstname);
    void setLastName(const std::string &lastname);
    void setNickName(const std::string &nickname);
    void setPhoneNumber(const std::string &number);
    void setDarkestSecret(const std::string &secret);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickName() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
};

void setData(const std::string &data, std::string *member);
void displayMember(const std::string &label, const std::string &value);

#endif