/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:38:52 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/08 21:40:41 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
: _name(name)
, _hit_points(10)
, _energy_points(10)
, _attack_damage(0)
{
    std::cout << "ClapTrap " << this->_name << " constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &original)
: _name(original._name)
, _hit_points(original._hit_points)
, _energy_points(original._energy_points)
, _attack_damage(original._attack_damage)
{
    std::cout << "ClapTrap " << this->_name << "Copy constructor called" << std::endl;
}


ClapTrap& ClapTrap::operator=(const ClapTrap& original)
{
    if (this != &original)
    {
        this->_name = original._name;
        this->_hit_points = original._hit_points;
        this->_energy_points = original._energy_points;
        this->_attack_damage = original._attack_damage;
    }
    std::cout << "ClapTrap " << this->_name << " Copy assignment operator called" << std::endl;
    return *this;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->_name << " Destructor called" << std::endl;
}

/* ************************************************************************** */
void    ClapTrap::attack(const std::string& target)
{
    if (this->_hit_points > 0 && this->_energy_points > 0)
    {
        std::cout << "ClapTrap " << this->_name <<" attacks " << target << " , causing " << this->_attack_damage << " points of damage!" << std::endl;
        this->_energy_points--;
    }
    else if (this->_hit_points > 0 && this->_energy_points <= 0)
    {
        std::cout << "ClapTrap " << this->_name <<" is not able to attack, because He does not have energy_points" << std::endl;
    }
    if (this->_hit_points <= 0)
        std::cout << "ClapTrap " << this->_name <<" is not able to attack, because He does not have hit_points" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hit_points > 0)
    {
        this->_hit_points -= amount;
        std::cout << "ClapTrap " << this->_name << " was attacked and lost " << amount << " hit_points, Now hit_points is " << this->_hit_points << std::endl;
    }
    else
	{
		std::cout << "ClapTrap " << this->_name << " is already dead " << std::endl;
		return ;
	}	
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points > 0 && this->_hit_points > 0)
	{
		this->_hit_points += amount;
		std::cout << "ClapTrap " << this->_name << " repaired itself and gained " << amount << " of hit points, Now hit_points is " << this->_hit_points << std::endl;
		this->_energy_points--;
	}
	else if (this->_energy_points <= 0)
		std::cout << "ClapTrap " << this->_name << " is not able to repair itself, because He does not have energy_points " << std::endl;
	else if (this->_hit_points <= 0)
		std::cout << "ClapTrap " << this->_name << " is not able to repair itself, because He does not have hit_points " << std::endl;
}