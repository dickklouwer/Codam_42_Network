/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Weapon.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 15:37:08 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 10:14:51 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon {
    private:
        std::string _type;

    public:
        Weapon(std::string _type);
        ~Weapon();
        const std::string   &getType(void);
        void                setType(std::string type);    
};

#endif