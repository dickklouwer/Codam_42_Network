/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   harl.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 15:37:12 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/25 10:11:00 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class Harl {
    private:
        void    debug( void );
        void    info( void );
        void    warning ( void );
        void    error( void );
    
    public:
        Harl();
        ~Harl();
        void complain(std::string level);
};

typedef void (Harl::*funcPtr) (void);

#endif