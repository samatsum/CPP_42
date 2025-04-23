/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:19:21 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 23:34:38 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie *newZombie( std::string name )
{
	Zombie *heap_zombie;

	try
	{
		heap_zombie = new Zombie(name);
	}
	catch (std::bad_alloc& e)
	{
		std::cerr << e.what() << std::endl;
		exit(1);
  	}
	return (heap_zombie);
}
