/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:18:44 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 13:06:29 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
	Zombie *newZombie_array;
	
	newZombie_array = newZombie("Samatsum");
	newZombie_array->announce();
	randomChump("A");
	randomChump("B");
	randomChump("C");
	randomChump("D");
	randomChump("E");
	randomChump("F");
	randomChump("G");
	delete newZombie_array;
	return (0);
}