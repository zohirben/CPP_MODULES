#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = copy;
}

Fixed::Fixed(const int &intNmb)
{
    std::cout << "Int constructor called" << std::endl;
    this->FixedPointValue = intNmb * (1 << this->ShiftAmount);
}
Fixed::Fixed(const float &floatNmb)
{
    std::cout << "Float constructor called" << std::endl;
    this->FixedPointValue = roundf((floatNmb * (1 << this->ShiftAmount)));
}

Fixed &Fixed::operator=(const Fixed &other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        this->FixedPointValue = other.FixedPointValue;
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Fixed &obj)
{
    os << obj.toFloat();
    return (os);
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

float Fixed::toFloat(void) const
{
    return ((float)this->FixedPointValue / (1 << this->ShiftAmount));
}
int Fixed::toInt(void) const
{
    return int(this->FixedPointValue / (1 << this->ShiftAmount));
}

bool Fixed::operator<(const Fixed &other) const
{
}
bool Fixed::operator>(const Fixed &other) const
{
}
bool Fixed::operator>=(const Fixed &other) const
{
}
bool Fixed::operator<=(const Fixed &other) const
{
}
bool Fixed::operator==(const Fixed &other) const
{
}
bool Fixed::operator!=(const Fixed &other) const
{
}
// arithmetic
Fixed Fixed::operator+(const Fixed &other) const
{
}
Fixed Fixed::operator-(const Fixed &other) const
{
}
Fixed Fixed::operator*(const Fixed &other) const
{
}
Fixed Fixed::operator/(const Fixed &other) const
{
}

// increment/decrement
Fixed &Fixed::operator++()
{
}
Fixed &Fixed::operator++(int)
{
}
Fixed &Fixed::operator--()
{
}
Fixed &Fixed::operator--(int)
{
}
// min & max
static Fixed &Fixed::min(Fixed &fisrt, Fixed &second)
{
}
static Fixed &Fixed::min(const Fixed &fisrt, const Fixed &second)
{
}
static Fixed &Fixed::max(Fixed &fisrt, Fixed &second)
{
}
static Fixed &Fixed::max(const Fixed &fisrt, const Fixed &second)
{
}