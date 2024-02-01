/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanB.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 09:09:45 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 10:18:32 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "Weapon.hpp"

class HumanB {
    private:
        std::string _name;
        Weapon      *weapon;
    public:
        HumanB(std::string name);
        ~HumanB();
        void    attack();
        void    setWeapon(Weapon &Weapon);
    
};
#endif