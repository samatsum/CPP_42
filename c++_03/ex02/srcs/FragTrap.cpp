/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 01:27:37 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/07 02:34:22 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"
#include "../include/FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap()
{
    std::cout << "FragTrap Default Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name)
{
    std::cout << "FragTrap " << this->_name << " Constructor called" << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

FragTrap::FragTrap(const FragTrap &original)
: ClapTrap(original)
{
    std::cout << "FragTrap " << this->_name << " Copy Constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " Destructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &original)
{
    if (this != &original)
    {
        this->_name = original._name;
        this->_hit_points = original._hit_points;
        this->_energy_points = original._energy_points;
        this->_attack_damage = original._attack_damage;
    }
    std::cout << "FragTrap " << this->_name << " copy assignment operator called" << std::endl;
	return *this;
}

/* ************************************************************************** */

void	FragTrap::highFiveGuys(void)
{
	std::cout << "FragTrap " << this->_name << "asks for High Fives" << std::endl;
}