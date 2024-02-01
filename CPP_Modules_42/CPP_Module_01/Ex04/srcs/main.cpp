/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 10:37:51 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 14:43:56 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mySed.hpp"

int main(int argc, char **argv)
{
    if (argc != 4)
        std::cout << "Usage: Filename <str1> <str2>" << std::endl;
        
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    mySed sed(filename);
    sed.replaceString(s1, s2);
}