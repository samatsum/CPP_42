/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:31:35 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/15 15:56:45 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Contact.hpp"

const std::string&	Contact::get_firstname() const
{
	return (this->firstname);
}

const std::string&	Contact::get_lastname() const
{
	return (this->lastname);
}

const std::string&	Contact::get_nickname() const
{
	return (this->nickname);
}

const std::string&	Contact::get_secret() const
{
	return (this->secret);
}

const std::string&	Contact::get_number() const
{
	return (this->number);
}

void		Contact::set_firstname(std::string firstname)
{
	this->firstname = firstname;
}

void		Contact::set_lastname(std::string lastname)
{
	this->lastname = lastname;
}

void		Contact::set_nickname(std::string nickname)
{
	this->nickname = nickname;
}

void		Contact::set_secret(std::string secret)
{
	this->secret = secret;
}

void		Contact::set_number(std::string number)
{
	this->number = number;
}
