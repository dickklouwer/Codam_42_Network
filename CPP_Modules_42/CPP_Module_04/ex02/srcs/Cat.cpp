/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Cat.cpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 08:26:51 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/23 14:14:23 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Cat.hpp"

Cat::Cat( void ) : Animal("Cat")
{
    this->_brain = new Brain();
}

Cat::~Cat()
{
    delete this->_brain;
}

void    Cat::makeSound() const
{
    std::cout << "MeeoooooWwWw" << std::endl;
}