/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:01:23 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/22 23:34:59 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

void Zombie::setName(std::string name)
{
    this->_name = name;
    std::cout << "Zombie \"" << this->_name << "\" created" << std::endl;
}

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *heap_array_zombie;

    try
    {
        heap_array_zombie = new Zombie[N];
    }
    catch (std::bad_alloc& e)
    {
        std::cerr << e.what() << std::endl;
        exit(1);
    }
    while (N--)
        heap_array_zombie[N].setName(name);
    return (heap_array_zombie);
}