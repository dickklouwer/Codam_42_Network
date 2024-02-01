/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:52:53 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/11 11:06:54 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() {
    this->_fixedPoint = 0;
}

Fixed::Fixed(const int fp) {
    this->_fixedPoint = fp << this->_fractBits;
}

Fixed::Fixed(const float fp) {
    this->_fixedPoint = roundf(fp * (1 << this->_fractBits));
}

Fixed::~Fixed() {
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    if (this != &other) {
        this->_fixedPoint = other.getRawBits();
    }
    return *this;
}

int     Fixed::getRawBits ( void ) const
{
    return (this->_fixedPoint);
}
        
void    Fixed::setRawBits( int const raw )
{
    this->_fixedPoint = raw;
}
float   Fixed::toFloat(void) const
{
    return ((float)_fixedPoint / (1 << _fractBits));
}

int     Fixed::toInt (void) const
{
    return (_fixedPoint >> _fractBits);
}

std::ostream& operator<<(std::ostream& os, const Fixed& obj) {
    os << obj.toFloat();
    return os;
}

bool    Fixed::operator>(const Fixed& other) const
{
    return (_fixedPoint > other._fixedPoint);
}

bool    Fixed::operator<(const Fixed& other) const
{
    return (_fixedPoint < other._fixedPoint);
}

bool    Fixed::operator>=(const Fixed& other) const
{
    return (_fixedPoint >= other._fixedPoint);
}

bool    Fixed::operator<=(const Fixed& other) const
{
    return (_fixedPoint <= other._fixedPoint);
}

bool    Fixed::operator==(const Fixed& other) const
{
    return (_fixedPoint == other._fixedPoint);
}

bool    Fixed::operator!=(const Fixed& other) const
{
    return (_fixedPoint != other._fixedPoint);
}

Fixed Fixed::operator+(const Fixed& other) const
{
    float result;
    
    result = this->toFloat() + other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator-(const Fixed& other) const
{
    float result;
    
    result = this->toFloat() - other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator*(const Fixed& other) const
{
    float result;

    result = this->toFloat() * other.toFloat();
    return Fixed(result);
}

Fixed Fixed::operator/(const Fixed& other) const
{
    float result;

    if (other._fixedPoint == 0)
        throw std::invalid_argument("Division by zero");
    result = this->toFloat() / other.toFloat();
    return Fixed(result);
}

Fixed& Fixed::operator++( void )
{
    ++_fixedPoint;
    return *this;
}

Fixed& Fixed::operator--( void )
{
    --_fixedPoint;
    return *this;
}

Fixed   Fixed::operator++(int)
{
    Fixed temp(*this);
    ++_fixedPoint;
    return temp;
}

Fixed   Fixed::operator--(int)
{
    Fixed temp(*this);
    --_fixedPoint;
    return temp;
}
