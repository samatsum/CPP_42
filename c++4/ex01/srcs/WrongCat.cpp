/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 16:13:17 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 16:13:49 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
    this->_type = "WrongCat";
    std::cout << "WrongCat Default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &original) : WrongAnimal(original)
{
    std::cout << "WrongCat Copy constructor called" << std::endl;
}


WrongCat& WrongCat::operator=(const WrongCat& original)
{
    if (this != &original)
    {
        WrongAnimal::operator=(original);
    }
    std::cout << "WrongCat " << this->_type << " Copy assignment operator called" << std::endl;
    return *this;
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat " << this->_type << " Destructor called" << std::endl;
}

/* ************************************************************************** */

void WrongCat::makeSound(void) const
{
    std::cout << "WrongCat says: I should meow but this won't be called with polymorphism!" << std::endl;
}
