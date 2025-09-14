/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:09:53 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 19:22:46 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon(const std::string& type)
{
    this->_type = type; 
}

void	Weapon::setType(std::string weapon_type)
{
    this->_type = weapon_type;
}

const	std::string& Weapon::getType()
{
    return (this->_type);
}

