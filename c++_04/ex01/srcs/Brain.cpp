/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 21:46:15 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 23:03:54 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
    int i;

	i = 0;
	while (i < 100)
	{
		ideas[i] = "Idea";
		i++;
	}
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called\n";
    for (int i = 0; i < 100; ++i)
    {
        ideas[i] = other.ideas[i];
    }
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain copy assignment operator called\n";
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
        {
            ideas[i] = other.ideas[i];
        }
    }
    return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain deconstructor called\n";
}