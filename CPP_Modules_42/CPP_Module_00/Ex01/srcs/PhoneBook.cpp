/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.cpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 09:33:42 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/03/24 11:13:05 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    this->_index = 0;
}

PhoneBook::~PhoneBook()
{
    return ;
}

void    PhoneBook::AddContact()
{
    std::string _continue;
    
    if (this->_index > 7)
    {
        std::cout << "Your PhoneBook is FULL." << std::endl;
        std::cout << "If you continue the next added Contact will overwrite the oldest." << std::endl;
        std::cout << "Continue? y / n?" << std::endl;
        std::cin >> _continue;
        if (_continue.compare("y") == 0)
        {
            _Contacts[_index % 8].add(this->_index % 8); 
            std::cout << "Oldest contact is overwritten at Index: " << this->_index % 8 << std::endl;
            _index++;
        }
        else
            return ;
    }
    else
    {
        _Contacts[_index % 8].add(this->_index % 8); 
        std::cout << "Contact added to your PhoneBook, at Index: " << this->_index % 8 << std::endl;
        _index++;
    }
    return ;
}

void PhoneBook::DisplayContact(int index)
{
    std::cout << "|" << std::setw(10) << index << std::flush;
    std::cout << "|" << std::setw(10) << _Contacts[index].getFirstName() << std::flush;
    std::cout << "|" << std::setw(10) << _Contacts[index].getLastName() << std::flush;
    std::cout << "|" << std::setw(10) << _Contacts[index].getNickName() << std::flush;
    std::cout << "|" << std::endl;
}

int getIntput()
{
    int input = -1;
    
    while (true)
    {
        std::cin.clear();
        std::cin >> input;   
        if (std::cin.fail() || input < 0 || input >= 8)
        {
            std::cout << "Invalid input.Please enter an integer between 0 and 7." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        return input;
    }
}

void    PhoneBook::SpecificContact()
{
    int         _indexToFind = -1;
    if (this->_index == 0)
        return ;
    std::cout << std::endl;
    std::cout << "Which Contact would you like to see?\nIndex: ";
    _indexToFind = getIntput();
    if ((_indexToFind >= 0 && _indexToFind < 8))
    {  
        if (_Contacts[_indexToFind].getFirstName().empty())
            std::cout << "Error: Contact doesn't exist yet" <<  std::endl;
        else
        {
            std::cout << "=============================================" << std::endl;
            std::cout << "=========          CONTACT " << _indexToFind << "        =========" << std::endl;
            std::cout << "=============================================" << std::endl;
            std::cout << "Index:        " << _indexToFind << std::endl;
            std::cout << "First Name:   " << _Contacts[_indexToFind].getFirstName() << std::endl;
            std::cout << "Last Name:    " << _Contacts[_indexToFind].getLastName()  << std::endl;
            std::cout << "Nick Name:    " << _Contacts[_indexToFind].getNickName() << std::endl;
            return ;
        }
    }
    else
    {
        std::cout << "Error: Index out of range." << std::endl;
        return ;
    }   
}

void    PhoneBook::SearchContact()
{
    if (_index == 0)
    {
        std::cout << "Error: No contacts added to your PhoneBook yet" << std::endl;
        return ;
    }
    std::cout << "=============================================" << std::endl;
    std::cout << "=========    PHONEBOOK CONTACTS    ==========" << std::endl;
    std::cout << "=============================================" << std::endl;
    std::cout << "|" << std::setw(10) << "Index" << std::flush;
    std::cout << "|" << std::setw(10) << "First Name" << std::flush;
    std::cout << "|" << std::setw(10) << "Last Name" << std::flush;
    std::cout << "|" << std::setw(10) << "Nick Name" << std::flush;
    std::cout << "|" << std::endl;
    for (int i = 0; i < 8; i++)
    {
        DisplayContact(i);
    }
    return ;
}