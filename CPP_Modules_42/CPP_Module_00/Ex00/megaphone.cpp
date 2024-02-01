/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   megaphone.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 09:33:38 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/08 12:12:56 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    for (int i = 1; i < argc; i++)
    {
        std::string argument = argv[i];
        for (size_t j = 0; j < argument.size(); j++)
             std::cout << (char)toupper(argv[i][j]);
    }
    std::cout << std::endl;
    return 0;
}