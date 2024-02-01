/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   animal.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 12:20:13 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/22 08:59:11 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Animal.hpp"

Animal::Animal( void ) : _type("Animal") 
{
    std::cout << this->_type << "Constructor called ..." << std::endl;
}

Animal::Animal(std::string type) : _type(type) 
{
    std::cout << this->_type << " Constructor called ..." << std::endl;
}

Animal::~Animal( void )
{
    std::cout << "Animal Destructor called ..." << std::endl;
}

Animal::Animal (const Animal& other)
{
    std::cout << "Animal Copy Constructor called ..." << std::endl;
    *this = other;
}

Animal& Animal::operator=( const Animal& other) 
{
    std::cout << "Animal Assignment Operator called ..." << std::endl;
    if (this != &other)
        this->_type = other._type;
    return *this;
}

void    Animal::makeSound ( void ) const
{
    std::cout << "* Animal Makes Sound *" << std::endl;
}

std::string Animal::getType() const
{
    return (this->_type);
}