/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 15:54:27 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/25 11:30:09 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/harl.hpp"

int main()
{
    Harl harl;
    std::string level;
    
    while (level != "EXIT")
    {
        std::cout << "Complain? 'debug' - 'info' - 'warning' - 'error'" << std::endl;
        std::cin >> level;
        harl.complain(level);
        std::cout << std::endl;
    }
}