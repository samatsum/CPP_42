/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 01:27:37 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 17:06:29 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog()
: Animal()
{
	this->_type = "Dog";
    _brain = new Brain();
    std::cout << "Dog " << this->_type << " Default constructor called" << std::endl;
}

Dog::Dog(const Dog &original)
: Animal(original)
{
	this->_type = original._type;
    _brain = new Brain(*(original._brain)); 
    std::cout << "Dog " << this->_type << " Copy constructor called" << std::endl;
}


Dog& Dog::operator=(const Dog& original)
{
    if (this != &original)
    {
        Animal::operator=(original);
        delete _brain;
        _brain = new Brain(*(original._brain));
    }
    std::cout << "Dog " << this->_type << " Copy assignment operator called" << std::endl;
    return *this;
}

Dog::~Dog()
{
    delete _brain;
    std::cout << "Dog " << this->_type << " Destructor called" << std::endl;
}
/* ************************************************************************** */

void Dog::makeSound(void) const
{
    std::cout << "Dog " << this->_type << " bark WAOOOOOOOONN!!!" << std::endl;
}

std::string Dog::get_idea(int idea_index) const
{
	if (idea_index >= 0 && idea_index < 100)
		return (_brain->ideas[idea_index]);
	else
		return ("Dog brain just have 100 ideas");
}

void Dog::set_idea(int idea_index, std::string new_idea)
{
	if (idea_index >= 0 && idea_index < 100)
		_brain->ideas[idea_index] = new_idea;
	else
		std::cout << "Dog " << this->_type << " brain can just save 100 ideas";
}