/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:10:10 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 19:27:16 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"
#include "../include/HumanA.hpp"

HumanA::HumanA(std::string name, Weapon weapon)
{
    this->_name = name;
    this->_weapon = weapon.getType();
}

void    HumanA::attack(void)
{
    std::cout << this->_name << " attacks with their " << this->_weapon << std::endl;
}