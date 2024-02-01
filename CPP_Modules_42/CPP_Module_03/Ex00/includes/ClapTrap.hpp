/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ClapTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/11 11:26:37 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/07 13:55:57 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap 
{
    private:
        std::string      _name;
        unsigned int     _hitPoints;
        unsigned int     _energyPoints;
        unsigned int     _attackDamage;

    public:
        ClapTrap(std::string _player);
        ~ClapTrap();
        ClapTrap(const ClapTrap& other);
        ClapTrap& operator=(const ClapTrap& other);

        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);

        unsigned int getHitpoints( void );
        std::string getName( void );
};

#endif