/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Brain.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/06/23 13:55:58 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/23 14:40:12 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain {
    private:
        std::string _ideas[100];

    public:
        Brain( void );
        ~Brain ( void );
        Brain (const Brain& other);
        Brain& operator=( const Brain& other);
};

#endif