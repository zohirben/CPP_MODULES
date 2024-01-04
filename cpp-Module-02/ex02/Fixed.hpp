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

    // comparison
    bool operator<(const Fixed &other) const;
    bool operator>(const Fixed &other) const;
    bool operator>=(const Fixed &other) const;
    bool operator<=(const Fixed &other) const;
    bool operator==(const Fixed &other) const;
    bool operator!=(const Fixed &other) const;    
    // arithmetic
    Fixed operator+(const Fixed &other) const;
    Fixed operator-(const Fixed &other) const;
    Fixed operator*(const Fixed &other) const;
    Fixed operator/(const Fixed &other) const;

    // increment/decrement
    Fixed &operator++();
    Fixed &operator++(int);
    Fixed &operator--();
    Fixed &operator--(int);
    // min & max
    static Fixed &min(Fixed &fisrt, Fixed &second);
    static Fixed &min(const Fixed &fisrt, const Fixed &second);
    static Fixed &max(Fixed &fisrt, Fixed &second);
    static Fixed &max(const Fixed &fisrt, const Fixed &second);

    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &os, const Fixed &obj);