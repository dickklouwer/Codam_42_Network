/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:32 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/11 10:23:56 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
    private:
        int                 _fixedPoint;
        static const int    _fractBits = 8;
    public:
        Fixed(); // Default constructor with immediate member initializer list 
        Fixed(const int fp);
        Fixed(const float fp);
        Fixed(const Fixed& other);  // Copy Contstructor
        Fixed& operator=(const Fixed& other);   // Copy assignment operator overload
        ~Fixed(); // Default destructor
        int     getRawBits ( void ) const;
        void    setRawBits( int const raw );
        int     toInt( void ) const;
        float   toFloat ( void ) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif