/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 09:12:16 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 10:18:54 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->_name = name;
}

HumanB::~HumanB()
{
}

void    HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void    HumanB::attack()
{
    std::cout << this->_name << " attacks with their " << weapon->getType() << std::endl;
}

