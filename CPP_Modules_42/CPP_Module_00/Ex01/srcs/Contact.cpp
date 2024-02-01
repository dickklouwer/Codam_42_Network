/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/13 13:47:32 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/03/24 11:20:37 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

Contact::Contact()
{
    return;
}

Contact::~Contact()
{
}

std::string getInput()
{
    std::string input;

    
    while (true)
    {
        std::getline(std::cin, input);
        if (std::cin.eof())
            exit(1);
        if (input.empty())
        {
            std::cout << "~ Remember input can't be empty" << std::endl;
            std::cout << "> " << std::flush;
        }
        else 
            return input;
    }
}

std::string    Contact::CheckTruncLength(std::string name)
{
    if (name.length() > 10)
    {
        name.resize(9);
        name.push_back('.');
    }
    return name;
}

void    Contact::add(int _index)
{
    this->_index = _index;
    std::cout << "Enter Firstname:\n";
    _FirstName = getInput();
    _FirstName = CheckTruncLength(_FirstName);

    std::cout << "Enter Last name:\n";
    _LastName = getInput();
    _LastName = CheckTruncLength(_LastName);

    std::cout << "Enter Nickname:\n";
    _NickName = getInput();
    _NickName = CheckTruncLength(_NickName);
    
    std::cout << "Enter Phonenumber:\n";
    _PhoneNum = getInput();
    
    std::cout << "Enter your Darkest Secret:\n";
    _DarkestSecret = getInput();
    return ;
}

std::string     Contact::getFirstName()
{
    return this->_FirstName;
}

std::string     Contact::getLastName()
{
    return this->_LastName;
}

std::string     Contact::getNickName()
{
    return this->_NickName;
}

int        Contact::getIndex()
{
    return this->_index;
}
