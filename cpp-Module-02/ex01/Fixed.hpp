#pragma once

#include <iostream>
#include <string>

class Fixed
{
private:
    int FixedPointValue;
    static const int ShiftAmount = 8;
public:
    Fixed();
    Fixed(const Fixed &copy);
    Fixed(const int &intnmb);
    Fixed(const float &floatNmb);
    Fixed& operator=(const Fixed &other);
    ~Fixed();

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);