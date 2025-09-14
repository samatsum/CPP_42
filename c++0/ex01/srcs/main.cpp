/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: samatsum  <zunandkun@gmail.com      >      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:30:41 by samatsum          #+#    #+#             */
/*   Updated: 2025/04/15 20:53:42 by samatsum         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PhoneBook.hpp"
#include <cctype>

static bool is_valid_input(const std::string& input)
{
    return !input.empty();
}

static bool is_digit_string(const std::string& str)
{
	int i;
    if (str.empty())
        return false;
	i = 0;
	while (i < str.length())
    {
        if (str[i] < '0' || str[i] > '9')
            return false;
		i++;
    }
    return true;
}

static void handle_add_command(PhoneBook &phonebook)
{
    std::string data[5];

    std::cout << COLOR_BLUE << "\nEnter Contact Information" << COLOR_RESET << std::endl;
	while (1)
	{
        std::cout << "First Name: ";
        std::getline(std::cin, data[0]);
        if (is_valid_input(data[0]))
            break;
        std::cout << COLOR_RED << "Field cannot be empty." << COLOR_RESET << std::endl;
    }
	while (1)
	{
        std::cout << "Last Name: ";
        std::getline(std::cin, data[1]);
        if (is_valid_input(data[1]))
            break;
        std::cout << COLOR_RED << "Field cannot be empty." << COLOR_RESET << std::endl;
    }
	while (1)
	{
        std::cout << "NickName: ";
        std::getline(std::cin, data[2]);
        if (is_valid_input(data[2]))
            break;
        std::cout << COLOR_RED << "Field cannot be empty." << COLOR_RESET << std::endl;
    }
	while (1)
	{
        std::cout << "Phone Number: ";
        std::getline(std::cin, data[3]);
        if (!is_valid_input(data[3])) {
            std::cout << COLOR_RED << "Field cannot be empty." << COLOR_RESET << std::endl;
            continue;
        }
        if (is_digit_string(data[3]))
            break;
        std::cout << COLOR_RED << "Please input a valid number (digits only)." << COLOR_RESET << std::endl;
    }
	while (1)
	{
        std::cout << "Darkest Secret: ";
        std::getline(std::cin, data[4]);
        if (is_valid_input(data[4]))
            break;
        std::cout << COLOR_RED << "Field cannot be empty." << COLOR_RESET << std::endl;
    }
	phonebook.add_contact(data);
    std::cout << COLOR_GREEN << "Contact Added Successfully!" << COLOR_RESET << std::endl;

}

static void handle_search_command(PhoneBook &phonebook)
{
    int index;
    std::string input;

    phonebook.display_phonebook();
    std::cout << COLOR_YELLOW << "\nInsert Index: " << COLOR_RESET;
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index >= phonebook.get_size())
    {
        std::cout << COLOR_RED << "Invalid input! Please enter a Valid Number." << COLOR_RESET << std::endl;
        std::cin.clear();
        std::getline(std::cin, input);
        return;
    }
    phonebook.display_contact(index);
    std::cin.clear();
    std::getline(std::cin, input);
}

int main()
{
    PhoneBook phonebook;
    std::string input;

    while (42)
    {
        std::cout << COLOR_BLUE << "Please Command (ADD, SEARCH, EXIT)> " << COLOR_RESET;
        std::getline(std::cin, input);
        if (input == "ADD")
            handle_add_command(phonebook);
        else if (input == "SEARCH")
            handle_search_command(phonebook);
        else if (input == "EXIT")
            break;
    }
    return (0);
}
