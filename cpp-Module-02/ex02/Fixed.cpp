#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
    this->FixedPointValue = 0;
}

Fixed::Fixed(const Fixed &copy)
{
    *this = copy;
}

Fixed::Fixed(const int &intNmb)
{
    this->FixedPointValue = intNmb * (1 << this->ShiftAmount);
}
Fixed::Fixed(const float &floatNmb)
{
    this->FixedPointValue = roundf((floatNmb * (1 << this->ShiftAmount)));
}

Fixed &Fixed::operator=(const Fixed &other)
{
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
    return this->FixedPointValue < other.FixedPointValue;
}
bool Fixed::operator>(const Fixed &other) const
{
    return this->FixedPointValue > other.FixedPointValue;
}
bool Fixed::operator>=(const Fixed &other) const
{
    return this->FixedPointValue >= other.FixedPointValue;
}
bool Fixed::operator<=(const Fixed &other) const
{
    return this->FixedPointValue <= other.FixedPointValue;
}
bool Fixed::operator==(const Fixed &other) const
{
    return this->FixedPointValue == other.FixedPointValue;
}
bool Fixed::operator!=(const Fixed &other) const
{
    return this->FixedPointValue != other.FixedPointValue;
}
// arithmetic
Fixed Fixed::operator+(const Fixed &other) const
{
    return Fixed(this->FixedPointValue + other.FixedPointValue);
}
Fixed Fixed::operator-(const Fixed &other) const
{
    return Fixed(this->FixedPointValue - other.FixedPointValue);
}
Fixed Fixed::operator*(const Fixed &other) const
{
    return Fixed(this->toFloat() * other.toFloat());
}
Fixed Fixed::operator/(const Fixed &other) const
{
    if (other.FixedPointValue == 0)
    {
        std::cout << "Division by zero" << std::endl;
        exit(1);
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// increment/decrement
Fixed &Fixed::operator++()
{
    ++this->FixedPointValue;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed temp(*this);
    ++this->FixedPointValue;
    return temp;
}

Fixed &Fixed::operator--()
{
    --this->FixedPointValue;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed temp(*this);
    --this->FixedPointValue;
    return temp;
}

// min & max
Fixed &Fixed::min(Fixed &first, Fixed &second)
{
    return (first < second) ? first : second;
}
const Fixed &Fixed::min(const Fixed &first, const Fixed &second)
{
    return (first < second) ? first : second;
}
Fixed &Fixed::max(Fixed &first, Fixed &second)
{
    return (first > second) ? first : second;
}
const Fixed &Fixed::max(const Fixed &first, const Fixed &second)
{
    return (first > second) ? first : second;
}
