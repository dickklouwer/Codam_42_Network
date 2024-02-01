/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 09:04:16 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 14:52:54 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
    public:
        Zombie();
        ~Zombie();
        void    announce( void );
        void    setName(std::string name);
        Zombie  *zombieHorde(int N, std::string name);
    private:
        std::string _name;
};

Zombie  *zombieHorde(int N, std::string name);
#endif