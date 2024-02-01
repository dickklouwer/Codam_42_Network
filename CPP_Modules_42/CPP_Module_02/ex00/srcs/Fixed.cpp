/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:52:53 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/09 12:18:21 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Fixed.hpp"

Fixed::~Fixed() {
    std::cout << "Destructor Called" << std::endl ;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy Constructor Called" << std::endl;
    this->fixed_point = other.getRawBits();
}
    
Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy Assignment Operator Called" << std::endl;
    if (this == &other)
    {
        return *this;
    }
    this->fixed_point = other.getRawBits();
    return (*this);
}

int     Fixed::getRawBits ( void ) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}
        
void    Fixed::setRawBits( int const raw )
{
    std::cout << "setRawBits member function called" << std::endl;
    this->fixed_point = raw;
}  