/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/06 23:52:28 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

int main()
{
	ClapTrap a("Bob");
	ClapTrap b("Jim");

	a.attack("Micky");
	a.takeDamage(10);
	a.takeDamage(10);
	a.beRepaired(5);
	a.attack("Micky");
	b.beRepaired(3);
	for (int i = 0; i < 12; i++)
		b.attack("Micky");
	b.beRepaired(3);
}
