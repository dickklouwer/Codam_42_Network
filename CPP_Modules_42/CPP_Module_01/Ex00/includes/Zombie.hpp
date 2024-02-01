/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Zombie.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 09:04:16 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 11:39:14 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie {
    public:
        Zombie(std::string name);
        ~Zombie();
        void announce( void );
        Zombie  *newZombie(std::string name);
        void    randomChump(std::string name);
    private:
        std::string _name;
};

Zombie  *newZombie(std::string name);
void    randomChump(std::string name);
#endif