/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 09:08:37 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 12:26:30 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie::Zombie()
{
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}

Zombie::~Zombie()
{
    std::cout << "Zombie: " << this->_name << " is destroyed.." << std::endl;
}

void    Zombie::announce()
{
    std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}