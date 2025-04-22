/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:10:17 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 19:29:16 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"
#include "../include/HumanB.hpp"

HumanB::HumanB(std::string name)
{
    this->_name = name;
}

void    HumanB::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon << std::endl;
}

void    HumanB::setWeapon(Weapon weapon)
{
    this->_weapon = weapon.getType();
}