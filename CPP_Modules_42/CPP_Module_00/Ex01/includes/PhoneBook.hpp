/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PhoneBook.hpp                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/08 09:34:38 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/02/16 11:44:29 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "Contact.hpp"

class PhoneBook {
    public:
        PhoneBook();
        ~PhoneBook();
        void            AddContact();
        void            SearchContact();
        void            DisplayContact(int index);
        void            SpecificContact();
    private:
        Contact _Contacts[8];
        int     _index;
};

#endif
