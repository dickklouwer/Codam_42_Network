/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   WrongAnimal.hpp                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 07:51:37 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/23 07:54:21 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    protected:
        std::string _type;
    public:
        WrongAnimal();
        WrongAnimal(std::string _type);
        virtual ~WrongAnimal();
        WrongAnimal (const WrongAnimal& other);
        WrongAnimal& operator=( const WrongAnimal& other);
        virtual void    makeSound ( void ) const;
        std::string getType() const;
};

#endif