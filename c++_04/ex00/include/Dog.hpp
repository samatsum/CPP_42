/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 01:27:23 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/09 15:54:32 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{
	private:
		std::string _type;
	public:
		Dog();
		Dog(const Dog &copy);
        ~Dog();
		Dog &operator=(const Dog &src);

        void makeSound(void);
};

#endif