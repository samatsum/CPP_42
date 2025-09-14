/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 15:09:25 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 16:11:33 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
: _type("WrongAnimal")
{
    std::cout << "WrongAnimal Default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &original)
: _type(original._type)
{
    std::cout << "WrongAnimal " << this->_type << " Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& original)
{
    if (this != &original)
    {
        this->_type = original._type;
    }
    std::cout << "WrongAnimal " << this->_type << " Copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal " << this->_type << " Destructor called" << std::endl;
}

/* ************************************************************************** */

std::string WrongAnimal::getType(void) const
{
    return this->_type;
}

void WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makes wrong sounds!" << std::endl;
}
