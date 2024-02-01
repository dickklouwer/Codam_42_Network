/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 09:17:45 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 11:52:58 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

int     main()
{
    std::string     name;
    std::cout << "Creating a Zombie on the Stack" << std::endl;
    std::cout << "Add a name to create a new Zombie:\n> ";
    std::cin >> name;
    Zombie stackZombie(name);
    stackZombie.announce();
    std::cout << std::endl;
    
    
    std::cout << "Creating a zombie on the heap using the 'new' operator" << std::endl;
    std::cout << "Add a name to create a new Zombie:\n> ";
    std::cin >> name;
    Zombie *heapZombie = newZombie(name);
    heapZombie->announce();
    delete heapZombie; // For every call to new there has to be a call to "Delete" (Free);
    std::cout << std::endl;

    std::cout << "Call to randomChump" << std::endl;
    randomChump("randomZombie");
    std::cout << std::endl;
    return (EXIT_SUCCESS);
}