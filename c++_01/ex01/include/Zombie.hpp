/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 12:18:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/01 16:51:03 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#pragma once

#include <string>
#include <iostream>
#include <new>
#include <cstdlib>

class Zombie
{
private:
	std::string _name;
public:
	Zombie();
	Zombie(std::string name);
	~Zombie(void);
	void announce(void);
	void setName(std::string name);
};

Zombie* zombieHorde(int N, std::string name);

#endif