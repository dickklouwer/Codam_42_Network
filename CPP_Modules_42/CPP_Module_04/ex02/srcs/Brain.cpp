/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 14:05:23 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/23 14:40:43 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Created .." << std::endl;
}
Brain::~Brain()
{
    std::cout << "Brain Destroyed .." << std::endl;
}

Brain::Brain (const Brain& other)
{
    std::cout << "Brain Copy Constructor called ..." << std::endl;
    *this = other;
}

Brain& Brain::operator=( const Brain& other)
{
    std::cout << "Brain Assignment Operator called ..." << std::endl;
    if (this != &other) {
        for (int i = 0; i < 100; i++)
           this->_ideas[i] = other._ideas[i]; 
    }
    return *this;
}
