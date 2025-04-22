/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:31:22 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/15 21:14:38 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"

void	print_name(std::string str)
{
	unsigned int j;

	j = 0;
	if (str.length() > 10)
	{
		std::cout << str.substr(0, 9);
		std::cout << ".";
	}
	else
	{
		j = 0;
		while (j++ < 10 - str.length())
			std::cout << " ";
		std::cout << str;
	}
}


int 	PhoneBook::get_size() const
{
	return (this->size);
}

void	PhoneBook::add_contact(std::string data[5])
{
	int	index;

	index = this->phone_index;
	this->contacts[index].set_firstname(data[0]);
	this->contacts[index].set_lastname(data[1]);
	this->contacts[index].set_nickname(data[2]);
	this->contacts[index].set_number(data[3]);
	this->contacts[index].set_secret(data[4]);
	this->phone_index = (index + 1) % 8;

	if (this->size < 8)
		this->size++;
}

void	PhoneBook::display_contact(int i) const
{
	std::cout << COLOR_BLUE << "+----------+----------+----------+----------+" << COLOR_RESET << std::endl;
	std::cout << COLOR_BLUE << "|  Contact information for specified index  |" << COLOR_RESET << std::endl;
	std::cout << COLOR_BLUE << "+----------+----------+----------+----------+" << COLOR_RESET << std::endl;

	std::cout << "First Name    : " << this->contacts[i].get_firstname() << std::endl;
	std::cout << "Last Name     : " << this->contacts[i].get_lastname() << std::endl;
	std::cout << "Nickname      : " << this->contacts[i].get_nickname() << std::endl;
	std::cout << "Number        : " << this->contacts[i].get_number() << std::endl;
	std::cout << "Darkest Secret: " << this->contacts[i].get_secret() << std::endl;
}

void	PhoneBook::display_phonebook() const
{
	int index;

	index = 0;
	std::cout << COLOR_BLUE << "+----------+----------+----------+----------+" << COLOR_RESET << std::endl;
	std::cout << COLOR_BLUE << "|     index|first name| last name|  nickname|" << COLOR_RESET << std::endl;
	std::cout << COLOR_BLUE << "+----------+----------+----------+----------+" << COLOR_RESET << std::endl;
	while (index < this->size)
	{
		std::cout << COLOR_BLUE << "|         " << COLOR_RESET;
		std::cout << index;
		std::cout << COLOR_BLUE << "|" << COLOR_RESET;
		print_name(this->contacts[index].get_firstname());
		std::cout << COLOR_BLUE << "|" << COLOR_RESET;
		print_name(this->contacts[index].get_lastname());
		std::cout << COLOR_BLUE << "|" << COLOR_RESET;
		print_name(this->contacts[index].get_nickname());
		std::cout << COLOR_BLUE << "|" << COLOR_BLUE << std::endl;
		std::cout << COLOR_BLUE << "+----------+----------+----------+----------+" << COLOR_RESET << std::endl;
		index++;
	}
}
