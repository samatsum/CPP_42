/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:02:35 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 16:31:36 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat()
: Animal()
{
	this->_type = "Cat";
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &original)
: Animal(original)
{
	this->_type = original._type;
    std::cout << "Cat " << this->_type << " Copy constructor called" << std::endl;
}


Cat& Cat::operator=(const Cat& original)
{
    if (this != &original)
    {
        Animal::operator=(original);
    }
    std::cout << "Cat " << this->_type << " Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    std::cout << "Cat " << this->_type << " Destructor called" << std::endl;
}

/* ************************************************************************** */
void    Cat::makeSound(void) const
{
    std::cout << "Cat say Meow" << std::endl;
}
