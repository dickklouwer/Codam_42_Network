/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 13:42:00 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/03/30 13:34:46 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

void     welcome(void)
{
   std::cout << "╔═══╗───────────────────╔═══╦╗──────────╔══╗──────╔╗\n"
                 "║╔═╗║───────────────────║╔═╗║║──────────║╔╗║──────║║\n"
                 "║║─║╠╗╔╗╔╦══╦══╦══╦╗╔╦══╣╚═╝║╚═╦══╦═╗╔══╣╚╝╚╦══╦══╣║╔╗\n"
                 "║╚═╝║╚╝╚╝║║═╣══╣╔╗║╚╝║║═╣╔══╣╔╗║╔╗║╔╗╣║═╣╔═╗║╔╗║╔╗║╚╝╝\n"
                 "║╔═╗╠╗╔╗╔╣║═╬══║╚╝║║║║║═╣║──║║║║╚╝║║║║║═╣╚═╝║╚╝║╚╝║╔╗╗\n"
                 "╚╝─╚╝╚╝╚╝╚══╩══╩══╩╩╩╩══╩╝──╚╝╚╩══╩╝╚╩══╩═══╩══╩══╩╝╚╝\033[0m" << std::endl;
	std::cout << "Welcome to your Awesome PhoneBook !\n";
}

int main()
{
    PhoneBook   Book;
    std::string input = "";

    welcome();
    while (input.compare("EXIT"))
    {
        std::cout << "\nThe available options are : " << std::endl; 
        std::cout << "ADD - SEARCH - EXIT \n\n> ";
        std::getline (std::cin, input);
        if (std::cin.eof())
            break ;
        if (input.compare("ADD") == 0)
        {
            Book.AddContact();
        }
        else if (input.compare("SEARCH") == 0)
        {
            Book.SearchContact();
            Book.SpecificContact();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cin.clear();
    }
    return (0);
}