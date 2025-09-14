/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:38:42 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/07 01:25:49 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

// Includes
#include <string>
#include <iostream>

// classes

class ClapTrap
{
	protected:
		std::string _name;
		long _hit_points;
		long _energy_points;
		long _attack_damage;

	public:
		ClapTrap();
		ClapTrap(const ClapTrap &original);
		ClapTrap(std::string name);
		virtual ~ClapTrap();
		ClapTrap &operator=(const ClapTrap &original);
		void attack(const std::string &target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
};

#endif