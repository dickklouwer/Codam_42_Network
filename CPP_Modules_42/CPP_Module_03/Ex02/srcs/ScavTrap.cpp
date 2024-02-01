/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ScavTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 12:55:32 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/07 13:55:04 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    std::cout << "ScavTrap Constructor called ..." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called ..." << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
    std::cout << "Copy Constructor Called ..." << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    if (this != &other)
        ClapTrap::operator=(other);
    std::cout << "Copy assignment operator called ...";
    this->_name = other._name;
    this->_attackDamage = other._attackDamage;
    this->_energyPoints = other._energyPoints;
    this->_hitPoints = other._hitPoints;
    return *this;
}

void    ScavTrap::guardGate() {
    std::cout << this->getName() << " is now in Gate keeper mode .." << std::endl;
}

void    ScavTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0) {
        std::cout << "ScavTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " point of damage!" << std::endl;
        this->_energyPoints--;
        return ;
    }
    else {
        std::cout << "No energy to perform attack..." << std::endl;        
        return ;
    }
}