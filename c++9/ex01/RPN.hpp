/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgodecke <cgodecke@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:08:27 by cgodecke          #+#    #+#             */
/*   Updated: 2024/04/02 19:08:54 by cgodecke         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <sstream>
# include <exception>

class RPN
{
	private:
		std::stack<double> _stack;
		void _executeStack(double (RPN::*f)(double, double));
		double _plus(double a, double b);
		double _minus(double a, double b);
		double _multiply(double a, double b);
		double _divide(double a, double b);

	public:
		//Constructors
		RPN();
		RPN(const std::string  &inputStr);
		RPN(const RPN &other);
		RPN &operator=(const RPN &other);
		~RPN();

		//Getters
		double getResult() const;


		//Exceptions
		class invalidArgument : public std::runtime_error
		{
			public:
				explicit invalidArgument(const std::string& msg);
		};

		class emptyStack : public std::runtime_error
		{
			public:
				explicit emptyStack(const std::string& msg);
		};

		class divisionByZero : public std::runtime_error
		{
			public:
				explicit divisionByZero(const std::string& msg);
		};	
};

#endif
