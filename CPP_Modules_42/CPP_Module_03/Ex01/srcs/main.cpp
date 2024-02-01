/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 11:53:24 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/07 13:41:16 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"
#include <iostream>

int main() 
{
    ScavTrap _player1("Dick");

    _player1.takeDamage(4);
    std::cout << _player1.getName() << " now has " << _player1.getHitpoints() << " hit points left!" << std::endl;
    _player1.attack("Shoplifter");
    _player1.beRepaired(8);
    std::cout << _player1.getName() << " now has " << _player1.getHitpoints() << " hit points left!" << std::endl;
    _player1.guardGate();
}
