/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:02:35 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 17:06:56 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat()
: Animal()
{
	this->_type = "Cat";
    _brain = new Brain();
    std::cout << "Cat " << this->_type << " Default constructor called" << std::endl;
}

Cat::Cat(const Cat &original)
: Animal(original)
{
	this->_type = original._type;
    _brain = new Brain(*(original._brain));
    std::cout << "Cat " << this->_type << " Copy constructor called" << std::endl;
}


Cat& Cat::operator=(const Cat& original)
{
    if (this != &original)
    {
        Animal::operator=(original);
        delete _brain;
        _brain = new Brain(*(original._brain));
    }
    std::cout << "Cat " << this->_type << " Copy assignment operator called" << std::endl;
    return *this;
}

Cat::~Cat()
{
    delete _brain;
    std::cout << "Cat " << this->_type << " Destructor called" << std::endl;
}

/* ************************************************************************** */
void    Cat::makeSound(void) const
{
    std::cout << "Cat " << this->_type << " say Meow" << std::endl;
}


std::string Cat::get_idea(int idea_index) const
{
	if (idea_index >= 0 && idea_index < 100)
		return (_brain->ideas[idea_index]);
	else
		return ("Cat brain can remember 100 ideas");
}

void Cat::set_idea(int idea_index, std::string new_idea)
{
	if (idea_index >= 0 && idea_index < 100)
		_brain->ideas[idea_index] = new_idea;
	else
		std::cout << "Cat " << this->_type << " brain just save 100 ideas now";
}