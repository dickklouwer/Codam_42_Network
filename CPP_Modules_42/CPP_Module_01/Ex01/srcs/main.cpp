/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 09:17:45 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 12:29:24 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int     main()
{
    std::string name;
    int         amount;

    std::cout << "Creating an Horde of zombies.." << std::endl;
    std::cout << "Input zombie name:\n> ";
    std::cin >> name;
    std::cout << "How big do you want your zombie army to be:\n> ";
    std::cin >> amount;
    
    Zombie *zombieArmy = zombieHorde(amount, name);
    for (int i = 0; i < amount; i++)
    {
        zombieArmy[i].announce();
    }
    delete[] zombieArmy;
}