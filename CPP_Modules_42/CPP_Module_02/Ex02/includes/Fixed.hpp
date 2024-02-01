/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Fixed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/04/24 15:31:32 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/05/11 10:50:36 by tklouwer      ########   odam.nl         */
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
        Fixed(const int fp); // Constructor with integer assignment.
        Fixed(const float fp); // Constructor with float assignment.
        Fixed(const Fixed& other);  // Copy Contstructor
        Fixed& operator=(const Fixed& other);   // Copy assignment operator overload
        ~Fixed(); // Default destructor
        int     getRawBits ( void ) const;
        void    setRawBits( int const raw );
        int     toInt( void ) const;
        float   toFloat ( void ) const;
        bool operator>(const Fixed& other) const;
        bool operator<(const Fixed& other) const;
        bool operator>=(const Fixed& other) const;
        bool operator<=(const Fixed& other) const;
        bool operator==(const Fixed& other) const;
        bool operator!=(const Fixed& other) const;
        Fixed operator+(const Fixed& other) const;
        Fixed operator-(const Fixed& other) const;
        Fixed operator*(const Fixed& other) const;
        Fixed operator/(const Fixed& other) const;
        Fixed& operator++(void);
        Fixed& operator--(void);
        Fixed operator++(int);
        Fixed operator--(int);
        static Fixed& min(Fixed& a, Fixed& b) { return (a < b)? a : b; };
        static const Fixed& min(const Fixed& a, const Fixed& b) { return (a < b)? a : b; };
        static Fixed& max(Fixed& a, Fixed& b) { return (a > b)? a : b; };
        static const Fixed& max(const Fixed& a, const Fixed& b) { return (a > b)? a : b; };

};

// Operator overload
std::ostream& operator<<(std::ostream& os, const Fixed& obj);

#endif