/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Animal.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 11:48:43 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/07/11 09:40:48 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Brain.hpp"

class Animal {
    protected:
        Animal();
        Animal(std::string _type);
        std::string _type;
    public:
        virtual ~Animal();
        Animal (const Animal& other);
        Animal& operator=( const Animal& other);
        virtual void    makeSound ( void ) const = 0;
        std::string getType() const;
};

#endif
