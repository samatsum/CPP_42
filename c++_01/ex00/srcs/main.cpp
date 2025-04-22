/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:18:44 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 14:49:06 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
	Zombie *heapZombie;
	
	heapZombie = newZombie("Samatsum");
	heapZombie->announce();
	delete heapZombie;
	randomChump("A");
	randomChump("B");
	randomChump("C");
	randomChump("D");
	randomChump("E");
	randomChump("F");
	randomChump("G");
	return (0);
}
