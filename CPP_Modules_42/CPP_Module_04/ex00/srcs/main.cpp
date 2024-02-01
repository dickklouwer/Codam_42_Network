/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 08:38:46 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/23 08:04:27 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main()
{
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    const WrongAnimal* wrongA = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << wrongA->getType() << " " << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;

    wrongCat->makeSound(); //will output the WRONG cat sound!
    wrongA->makeSound();

    return 0;
    
}