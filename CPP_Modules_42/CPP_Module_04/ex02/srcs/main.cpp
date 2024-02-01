/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 08:38:46 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/07/11 09:46:01 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Dog.hpp"
#include "../includes/Cat.hpp"
#include "../includes/WrongCat.hpp"

int main()
{

	const Animal* j = new Dog();
    const Animal* i = new Cat();

    delete j; //should not create a leak
    delete i;

	std::cout << std::endl;

	const int SIZE = 2;
	Animal **animals = new Animal*[SIZE]; 
	for (int i = 0; i < SIZE; ++i)
	{
		if (i < SIZE / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();         
	}
	for (int i = 0; i < SIZE; ++i)
		delete animals[i];

	delete [] animals;

	return 0;
}
