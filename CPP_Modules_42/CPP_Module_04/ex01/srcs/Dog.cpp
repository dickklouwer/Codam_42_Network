
/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 08:26:51 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/22 08:37:34 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"

Dog::Dog( void ) : Animal("Dog")
{
    this->_brain = new Brain();
}

Dog::~Dog()
{
    delete this->_brain;
}

void    Dog::makeSound() const
{
    std::cout << "Wooof!" << std::endl;
}