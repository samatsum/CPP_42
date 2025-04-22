/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:31:11 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/15 20:55:57 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Contact.hpp"
#include <iostream>

#define COLOR_BLUE     "\033[1;34m"
#define COLOR_RED      "\033[1;31m"
#define COLOR_GREEN    "\033[1;32m"
#define COLOR_YELLOW   "\033[1;33m"
#define COLOR_RESET    "\033[0m"

class PhoneBook {
private:
	Contact	contacts[8];
	int 	size;
	int 	phone_index;
public:
	PhoneBook() : size (0), phone_index (0) {}
	int 	get_size(void) const;
	void	add_contact(std::string data[5]);
	void	display_contact(int i) const;
	void	display_phonebook(void) const;
};
