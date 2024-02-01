/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   zombieHorde.cpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 11:55:51 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 12:26:58 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

Zombie  *zombieHorde(int N, std::string name)
{
    Zombie *zombieArmy = new Zombie[N];
    for (int i = 0; i < N; i++)
    {
        zombieArmy[i].setName(name);
    }
    return (zombieArmy);
}