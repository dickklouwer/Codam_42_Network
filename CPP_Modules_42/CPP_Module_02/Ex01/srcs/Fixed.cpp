/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:52:53 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/11 10:24:17 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::Fixed() {
    this->_fixedPoint = 0;
    std::cout << "Default Constructor Called" << std::endl;
}

Fixed::Fixed(const int fp) {
    this->_fixedPoint = fp << this->_fractBits;
    std::cout << "Int Constructor Called" << std::endl;
}

Fixed::Fixed(const float fp) {
    this->_fixedPoint = roundf(fp * (1 << this->_fractBits));
    std::cout << "Float Constructor Called" << std::endl;
}

Fixed::~Fixed() {
    std::cout << "Destructor Called" << std::endl ;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy Constructor Called" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy Assignment Operator Called" << std::endl;
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
    std::cout << "setRawBits member function called" << std::endl;
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
