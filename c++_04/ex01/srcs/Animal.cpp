/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:41:08 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 16:10:34 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 19:38:52 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/08 17:00:15 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal()
: _type("Animal")
{
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &original)
: _type(original._type)
{
    std::cout << "Animal " << this->_type << " Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& original)
{
    if (this != &original)
    {
        this->_type = original._type;
    }
    std::cout << "Animal " << this->_type << " Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal()
{
    std::cout << "Animal " << this->_type << " Destructor called" << std::endl;
}

/* ************************************************************************** */

std::string Animal::getType(void) const
{
    return this->_type;
}

void Animal::makeSound(void) const
{
    std::cout << "Animal bark and make sound! " << std::endl;
}
