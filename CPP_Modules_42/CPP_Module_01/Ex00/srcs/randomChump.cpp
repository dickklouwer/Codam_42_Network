/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   randomChump.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 09:03:07 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 11:34:28 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

void    randomChump(std::string name)
{
    Zombie randomZombie = Zombie(name);
    randomZombie.announce();
}