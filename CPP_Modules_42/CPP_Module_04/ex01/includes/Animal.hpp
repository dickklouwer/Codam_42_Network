/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:48:43 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/23 14:13:48 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
    protected:
        std::string _type;
    public:
        Animal();
        Animal(std::string _type);
        virtual ~Animal();
        Animal (const Animal& other);
        Animal& operator=( const Animal& other);
        virtual void    makeSound ( void ) const;
        std::string getType() const;
};

#endif
