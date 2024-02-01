/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Dog.hpp                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/22 08:37:42 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/22 09:05:39 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef Dog_HPP
# define Dog_HPP

#include "Animal.hpp"

class Dog : public Animal {
    private:

    public:
        Dog( void );
        ~Dog( void );
        void    makeSound() const;
};

#endif