/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 09:56:33 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/07 14:02:35 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout << "FragTrap Constructor called ..." << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
    
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called ..." << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
    std::cout << "Copy Constructor called ..." << std::endl;
    *this = other;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
    if (this != &other)
        ClapTrap::operator=(other);
        std::cout << "Copy assignment operator called ...";
    this->_name = other._name;
    this->_attackDamage = other._attackDamage;
    this->_energyPoints = other._energyPoints;
    this->_hitPoints = other._hitPoints;
    return *this;
}

void    FragTrap::highFivesGuys(){
    std::cout << "High Five Guys!" << std::endl;
}

void    FragTrap::attack(const std::string& target)
{
    if (this->_energyPoints > 0) {
        std::cout << "FragTrap: " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " point of damage!" << std::endl;
        this->_energyPoints--;
        return ;
    }
    else {
        std::cout << "No energy to perform attack..." << std::endl;        
        return ;
    }
}
