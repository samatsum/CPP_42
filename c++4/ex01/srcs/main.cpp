/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum <samatsum@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 17:13:58 by samatsum          #+#    #+#             */
/*   Updated: 2025/05/12 17:06:29 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

#include <string>
#include <iostream>
#include <fstream>
#define ARRAY_SIZE 5

int main()
{

	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		std::cout << std::endl;

		delete j;//should not create a leak
		delete i;
	}

	std::cout << "----" << std::endl;

	{
		Animal* animal_arr[ARRAY_SIZE];

		int i = 0;
		while (i < ARRAY_SIZE)
		{
			if (i % 2 == 0)
				animal_arr[i] = new Dog();
			else
				animal_arr[i] = new Cat();
			i++;
		}

		i = 0;
		while ( i < ARRAY_SIZE)
		{
			std::cout << "This is a " << animal_arr[i]->getType() << std::endl;
			animal_arr[i]->makeSound();
			i++;
		}

		i = 0;
		while ( i < ARRAY_SIZE)
		{
			delete animal_arr[i];
			i++;
		}
	}

	std::cout << "----" << std::endl;

	{
		std::cout << "\033[33m" << "Deep Copy Test Cat Copy\n"<< "\033[0m";
		Cat cat;
		Cat copy_cat(cat);
		
		std::cout << std::endl;

		std::cout << "This is idea 10 from cat: " << cat.get_idea(10) << std::endl;
		cat.set_idea(10, "This is the new idea");
		std::cout << "This is the new idea 10 from cat: " << cat.get_idea(10) << std::endl;
		std::cout << "This is idea 10 from copy_cat: " << copy_cat.get_idea(10) << std::endl;
	}
	
	std::cout << "----" << std::endl;


	{
		std::cout << "\033[33m" << "Deep Copy Test Dog Assignment\n"<< "\033[0m";
		Dog dog;
		Dog assignment_dog(dog);
		std::cout << std::endl;
		
		std::cout << "This is idea 10 from dog: " << dog.get_idea(10) << std::endl;
		dog.set_idea(10, "This is the new idea to paint the moon");
		std::cout << "This is the new idea 10 from dog: " << dog.get_idea(10) << std::endl;
		std::cout << std::endl;

		std::cout << "This is idea 10 from assignment_dog before assignment: " << assignment_dog.get_idea(10) << std::endl;
		assignment_dog = dog;
		std::cout << "This is idea 10 from assignment_dog after assignment: " << assignment_dog.get_idea(10) << std::endl;
		std::cout << std::endl;

		assignment_dog.set_idea(10, "Better paint the mars!");
		std::cout << "This is the new idea 10 from assignment dog: " << assignment_dog.get_idea(10) << std::endl;
		std::cout << "This is idea 10 from dog: " << dog.get_idea(10) << std::endl;
	}
    std::cout << "----" << std::endl;

	return 0;
}
