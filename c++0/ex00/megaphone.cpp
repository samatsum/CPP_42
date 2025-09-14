/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 19:24:54 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/15 15:20:28 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void print_argument(char *argument)
{
	while (*argument != '\0')
	{
		if (std::isalpha(*argument))
			std::cout << (char)std::toupper(*argument);
		else
			std::cout << *argument;
		argument++;
	}
}

int main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		i = 1;
		while (argv[i] != NULL)
		{
			print_argument(argv[i]);
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}
