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
    Fixed& operator=(const Fixed &other);
    ~Fixed();

    int getRawBits(void) const;
    void setRawBits(int const raw);
};