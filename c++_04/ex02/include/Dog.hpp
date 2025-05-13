/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 01:27:23 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 19:41:08 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal
{
	private:
		Brain *_brain;
	public:
		Dog();
		Dog(const Dog &copy);
        ~Dog();
		Dog &operator=(const Dog &original);

        virtual void makeSound(void) const;
		std::string 	get_idea(int idea_index) const;
		void 			set_idea(int idea_index, std::string idea_str);
};

#endif