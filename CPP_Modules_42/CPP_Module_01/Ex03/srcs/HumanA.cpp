/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 09:14:29 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 10:19:00 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), weapon(weapon) 
{
}

HumanA::~HumanA()
{
}

void    HumanA::attack()
{
    std::cout << this->_name << " attacks with their " << weapon.getType() << std::endl;
}