/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mySed.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/22 12:28:29 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/22 14:58:39 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mySed.hpp"

mySed::mySed(std::string inFile) : _inFile(inFile)
{
    this->_outFile = _inFile + ".copy";
}

mySed::~mySed()
{    
}

void    mySed::replaceString(std::string oldStr, std::string newStr)
{
    std::ifstream inFile(this->_inFile);
    std::ofstream outFile(this->_outFile);
    if (!inFile.is_open())
    {
        std::cerr << "Failed to open file..." << std::endl;
        return ;
    }
        
    if (!outFile.is_open())
    {
        std::cerr << "Failed to open file..." << std::endl;
        return ;
    }

    std::string line;
    if (std::getline(inFile, line, '\0'))
    {
        size_t pos = 0;
        pos = line.find(oldStr, pos);
        while (pos != std::string::npos)
        {
            line.erase(pos, oldStr.length());
            line.insert(pos, newStr);
            pos = line.find(oldStr);
        }
        outFile << line;
    }
    inFile.close();
    outFile.close();
    return ;
}