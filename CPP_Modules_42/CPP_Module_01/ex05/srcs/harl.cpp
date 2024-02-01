/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   harl.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 15:38:53 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/25 11:30:33 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void    Harl::debug()
{
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void    Harl::info()
{
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void    Harl::complain(std::string level)
{    
    funcPtr complains[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    std::string levels[] = {"debug", "info", "warning", "error"};

    int i = 0;
    int numFuncs = sizeof(levels);
    std::cout << std::endl;
    for (int i = 0; i < numFuncs; i++)
    {
        if (level == levels[i]) {
            (this->*complains[i])();
            return ;
        }
                  
    }
    std::cerr << "Given complain doesn't exist" << std::endl;
}