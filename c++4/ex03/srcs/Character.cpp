/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 12:43:39 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 20:25:33 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"
#include "../include/Character.hpp"

Character::Character() : _name("unnamed")
{
    std::cout << "Character default constructor called" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
        this->_inventory[i] = NULL;
}

Character::Character(std::string const & name) : _name(name)
{
    std::cout << "Character parametric constructor called" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
        this->_inventory[i] = NULL;
}

Character::Character(const Character& original)
{
    std::cout << "Character copy constructor called" << std::endl;
    this->_name = original._name;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (original._inventory[i])
            this->_inventory[i] = original._inventory[i]->clone();
        else
            this->_inventory[i] = NULL;
    }
}

Character::~Character()
{
    std::cout << "Character destructor called" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (this->_inventory[i])
            delete this->_inventory[i];
    }
}

Character& Character::operator=(const Character& original)
{
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &original)
    {
        this->_name = original._name;
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
        }
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (original._inventory[i])
                this->_inventory[i] = original._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return *this;
}

/* ************************************************************************** */

std::string const & Character::getName() const
{
    return this->_name;
}

void Character::equip(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (!this->_inventory[i])
        {
            this->_inventory[i] = m;
            std::cout << this->_name << " equipped " << m->getType() << " at position " << i << std::endl;
            return;
        }
    }
    std::cout << this->_name << " can't equip " << m->getType() << " (inventory full)" << std::endl;
}

void Character::unequip(int idx)
{
    if (idx < 0 || idx >= ARRAY_SIZE || !this->_inventory[idx])
    {
        std::cout << this->_name << " has nothing to unequip at position " << idx << std::endl;
        return;
    }
    
    std::cout << this->_name << " unequipped " << this->_inventory[idx]->getType() << " from position " << idx << std::endl;
    this->_inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
    if (idx < 0 || idx >= ARRAY_SIZE || !this->_inventory[idx])
    {
        std::cout << this->_name << " can't use materia at position " << idx << std::endl;
        return;
    }
    
    this->_inventory[idx]->use(target);
}