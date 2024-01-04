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
    this->FixedPointValue = intNmb *  (1 << this->ShiftAmount);
}
Fixed::Fixed(const float &floatNmb)
{
    std::cout << "Float constructor called" << std::endl;
    this->FixedPointValue = roundf((floatNmb *  (1 << this->ShiftAmount)));
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