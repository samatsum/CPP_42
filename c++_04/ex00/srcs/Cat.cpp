/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:02:35 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 16:01:16 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat()
: Animal()
, _type("Cat")
{
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &original)
: Animal(original)
, _type(original._type)
{
    std::cout << "Cat Copy constructor called" << std::endl;
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
void    makeSound(void)
{
    std::cout << "Cat bark   ...nothing" << std::endl;
}
