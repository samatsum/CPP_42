/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 13:17:35 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 20:18:51 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AMateria.hpp"
#include "../include/ICharacter.hpp"

AMateria::AMateria() : _type("")
{
    std::cout << "AMateria default constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type)
: _type(type)
{
    std::cout << "AMateria parametric constructor called" << std::endl;
}

AMateria::AMateria(const AMateria& original)
: _type(original._type)
{
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria::~AMateria()
{
    std::cout << "AMateria destructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& original)
{
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &original)
    {
        this->_type = original._type;
    }
    return *this;
}

/* ************************************************************************** */
std::string const & AMateria::getType() const
{
    return this->_type;
}

void AMateria::use(ICharacter& target)
{
    std::cout << "* uses an undefined materia on " << target.getName() << " *" << std::endl;
}