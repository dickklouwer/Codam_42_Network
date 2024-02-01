/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   newZombie.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 09:12:04 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 11:12:09 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Zombie.hpp"

/*  The "new" operator allocates memory on the heap. 
    for every call to "new", there needs to be a call to "delete" to free the
    memory allocated and preventing memory leaks.
    Think of the "alloc" functions and "Free" in C.
 */
Zombie  *newZombie(std::string name)
{
    return (new Zombie(name));
}