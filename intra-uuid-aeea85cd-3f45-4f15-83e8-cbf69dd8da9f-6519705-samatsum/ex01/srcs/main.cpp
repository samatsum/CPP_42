/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:18:44 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 18:32:01 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main(void)
{
	Zombie *heap_array_zombie;
	int N;

	N = 3;
	heap_array_zombie = zombieHorde(N, "Heap_Array_Zombie");
	while (N--)
		heap_array_zombie[N].announce();
	delete[]  heap_array_zombie;
	return (0);
}
