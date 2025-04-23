/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:18:44 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 18:31:19 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
	Zombie *heap_zombie;
	
	heap_zombie = newZombie("Samatsum");
	heap_zombie->announce();
	randomChump("A");
	randomChump("B");
	randomChump("C");
	delete heap_zombie;
	return (0);
}
