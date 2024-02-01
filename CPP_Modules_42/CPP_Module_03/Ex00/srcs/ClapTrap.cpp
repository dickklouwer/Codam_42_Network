/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 11:28:50 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/07 13:53:57 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) {
    this->_name = name;
    this->_hitPoints = 10;
    this->_energyPoints = 10;
    this->_attackDamage = 0;
    std::cout << "Constructor called ..." << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called ..." << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "Copy Constructor Called ..." << std::endl;
    *this = other;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called ...";
    this->_name = other._name;
    this->_attackDamage = other._attackDamage;
    this->_energyPoints = other._energyPoints;
    this->_hitPoints = other._hitPoints;
    return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0) {
        std::cout << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " point of damage!" << std::endl;
        this->_energyPoints--;
        return ;
    }
    else {
        std::cout << "No energy to perform attack..." << std::endl;        
        return ;
    }
}

void    ClapTrap::takeDamage(unsigned int amount)
{
    std::cout << this->_name << " takes " << amount << " hitpoints damage from the attack..." << std::endl;
    if (amount > this->_hitPoints) {
        this->_hitPoints = 0;
        return ;
    }
    this->_hitPoints -= amount;
    return ;
}

void    ClapTrap::beRepaired(unsigned int amount)
{
    if (this->_energyPoints > 0) {
        std::cout << this->_name << " repairs himself for " << amount << " hit points" << std::endl;
        this->_energyPoints--;
        this->_hitPoints += amount;
        return ;
    }
    else {
        std::cout << "No energy to perform repair..." << std::endl;        
        return ;
    }
}
unsigned int ClapTrap::getHitpoints( void ) { return this->_hitPoints; };

std::string   ClapTrap::getName( void ) { return this->_name; } ;
