/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mySed.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:25:09 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 13:21:23 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSED_HPP
# define MYSED_HPP

#include <iostream>
#include <fstream>

class mySed {
    public:
        mySed(std::string _inFile);
        ~mySed();
        void replaceString(std::string oldStr, std::string newStr);

    private:
        std::string _inFile;
        std::string _outFile;
};

#endif