/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/21 15:04:24 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/21 15:34:10 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";

    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Memory address of the string: " << &str << std::endl;
    std::cout << "Memory address of the pointer to the string: " << std::hex << stringPTR << std::endl;
    std::cout << "Memory address of the reference to the string: " << &stringREF << std::endl;

    std::cout << "Value of the string: " << str << std::endl;
    std::cout << "Value of the pointer to the sring: " << *stringPTR << std::endl;
    std::cout << "Value of the reference to the string: " << stringREF << std::endl;
    
    return (EXIT_SUCCESS);
}