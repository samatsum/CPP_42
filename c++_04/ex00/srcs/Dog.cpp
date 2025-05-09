/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 01:27:37 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 16:01:23 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog()
: _type("Dog")
{
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &original)
: _type(original._type)
{
    std::cout << "Dog Copy constructor called" << std::endl;
}


Dog& Dog::operator=(const Dog& original)
{
    if (this != &original)
    {
        Animal::operator=(original);
    }
    std::cout << "Dog " << this->_type << " Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    std::cout << "Dog " << this->_type << " Destructor called" << std::endl;
}
/* ************************************************************************** */

void    makeSound(void)
{
    std::cout << "Dog bark   WAOOOOOOOONN!!!" << std::endl;
}
