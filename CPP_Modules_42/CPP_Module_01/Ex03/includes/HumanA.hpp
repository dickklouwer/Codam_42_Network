/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   HumanA.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 09:14:08 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 09:39:53 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "Weapon.hpp"

class HumanA {
    private:
        std::string _name;
        Weapon      &weapon;
    public:
        HumanA(std::string name, Weapon &Weapon);
        ~HumanA();
        void    attack();
    
};

#endif