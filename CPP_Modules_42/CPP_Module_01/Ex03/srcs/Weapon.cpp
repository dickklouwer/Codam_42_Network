/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 15:42:28 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 10:14:36 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Weapon.hpp"

Weapon::Weapon(std::string _type){
    this->setType(_type);
}

Weapon::~Weapon() {
}

const std::string &Weapon::getType(void)
{
    return (this->_type);
}

void    Weapon::setType(std::string type)
{
    this->_type = type;
}

