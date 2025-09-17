/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 10:21:37 by cgodecke          #+#    #+#             */
/*   Updated: 2024/04/02 18:01:59 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <exception>
# include <string>

class BitcoinExchange
{
	private:
		std::map<std::string, double>	_quotes;
		void _readDatabase();
		bool _validateDate(std::string const &date);
		double _validatePrice(std::string const &price);
		void _multiplyWithQuote(std::string const &date, double price);
	
	public:
		BitcoinExchange();
		BitcoinExchange(BitcoinExchange const &other);
		BitcoinExchange &operator=(BitcoinExchange const &other);
		~BitcoinExchange();

		std::map<std::string, double> const &getQuotes() const;
		void execute(char const *fileName);


		// Exceptions which printing error message
		class CouldNotOpenFile : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Could not open file");
				}
		};

		class InvalidColumnFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid column format. Expected 'date,exchange_rate'");
				}
		};

		class InvalidDateFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid date format. Expected 'YYYY-MM-DD'");
				}
		};

		class InvalidPriceFormat : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Invalid price format. Expected a number between 0.0 and 1000.0");
				}
		};
};

#endif
