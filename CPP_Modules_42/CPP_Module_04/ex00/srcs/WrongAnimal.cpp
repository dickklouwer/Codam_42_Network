/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 07:54:31 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/23 07:56:11 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type("WrongAnimal")
{
    std::cout << this->_type << "Constructor called ..." << std::endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type) 
{
    std::cout << this->_type << " Constructor called ..." << std::endl;
}

WrongAnimal::~WrongAnimal( void )
{
    std::cout << "WrongAnimal Destructor called ..." << std::endl;
}

WrongAnimal::WrongAnimal (const WrongAnimal& other)
{
    std::cout << "WrongAnimal Copy Constructor called ..." << std::endl;
    *this = other;
}

WrongAnimal& WrongAnimal::operator=( const WrongAnimal& other) 
{
    std::cout << "WrongAnimal Assignment Operator called ..." << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void    WrongAnimal::makeSound ( void ) const
{
    std::cout << "* WrongAnimal Makes Sound *" << std::endl;
}

std::string WrongAnimal::getType() const
{
    return (this->_type);
}