/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   FragTrap.hpp                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: tklouwer <tklouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/05/15 09:54:00 by tklouwer      #+#    #+#                 */
/*   Updated: 2023/06/07 14:00:42 by tklouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
    private:

    public:
        FragTrap(std::string name);
        ~FragTrap();
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);

        void highFivesGuys(void);
        void attack(const std::string& target);
};

#endif