/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:32 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/09 12:15:59 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
    private:
        int                 fixed_point;
        static const int    fract_bits = 8;
    public:
        Fixed() : fixed_point(0) { std::cout << "Default Constructor Called" << std::endl; } // Default constructor with immediate member initializer list 
        Fixed(const Fixed& other);  // Copy Contstructor
        Fixed& operator=(const Fixed& other);   // Copy assignment operator overload
        ~Fixed(); // Default destructor
        int     getRawBits ( void ) const;
        void    setRawBits( int const raw );     
};

#endif