/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongCat.cpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 07:58:44 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/23 08:00:21 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal("WrongCat") {
    
}

WrongCat::~WrongCat(){
    
}

void    WrongCat::makeSound() const
{
    std::cout << "WooooFFF!" << std::endl;
}
