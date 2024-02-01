/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Contact.hpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 09:39:16 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/03/07 14:12:04 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact {

    public:
        Contact();
        ~Contact();
        void            add(int _index);
        std::string     getFirstName();
        std::string     getLastName();
        std::string     getNickName();
        int             getIndex();
        std::string     CheckTruncLength(std::string name);

    private:
        std::string _FirstName;
        std::string _LastName;
        std::string _NickName;
        std::string _PhoneNum;
        std::string _DarkestSecret;
        int         _index;
};

#endif