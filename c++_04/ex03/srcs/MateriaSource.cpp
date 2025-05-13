/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 22:41:40 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 20:27:28 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    std::cout << "MateriaSource default constructor called" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
        this->_templates[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& original)
{
    std::cout << "MateriaSource copy constructor called" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (original._templates[i])
            this->_templates[i] = original._templates[i]->clone();
        else
            this->_templates[i] = NULL;
    }
}

MateriaSource::~MateriaSource()
{
    std::cout << "MateriaSource destructor called" << std::endl;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (this->_templates[i])
            delete this->_templates[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& original)
{
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &original)
    {
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (this->_templates[i])
                delete this->_templates[i];
        }
        for (int i = 0; i < ARRAY_SIZE; i++)
        {
            if (original._templates[i])
                this->_templates[i] = original._templates[i]->clone();
            else
                this->_templates[i] = NULL;
        }
    }
    return *this;
}

/* ************************************************************************** */

void MateriaSource::learnMateria(AMateria* m)
{
    if (!m)
        return;
        
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (!this->_templates[i])
        {
            this->_templates[i] = m;
            std::cout << "MateriaSource learned " << m->getType() << std::endl;
            return;
        }
    }
    std::cout << "MateriaSource can't learn more materias (slot is full)" << std::endl;
    delete m;
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (this->_templates[i] && this->_templates[i]->getType() == type)
        {
            std::cout << "MateriaSource created " << type << std::endl;
            return this->_templates[i]->clone();
        }
    }
    std::cout << "MateriaSource doesn't know materia type: " << type << std::endl;
    return NULL;
}