/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:19:08 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 15:13:49 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../include/Zombie.hpp"

Zombie::Zombie(void)
{	
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	std::cout << "Zombie \"" << this->_name << "\" created" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie \"" << this->_name << "\" destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}