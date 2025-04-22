/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:19:21 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 13:02:51 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie *newZombie( std::string name )
{
	Zombie *new_zombie;
	
	new_zombie = new Zombie(name);
	return (new_zombie);
}