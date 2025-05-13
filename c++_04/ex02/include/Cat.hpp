/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 00:02:44 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 19:41:08 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
	private:
		Brain *_brain;
	public:
		Cat();
		Cat(const Cat &copy);
        ~Cat();
		Cat &operator=(const Cat &original);

		virtual void makeSound(void) const;
		std::string 	get_idea(int idea_index) const;
		void 			set_idea(int idea_index, std::string idea_str);
};

#endif