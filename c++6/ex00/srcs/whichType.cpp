#include "../includes/ScalarConverter.hpp"

/* ************************************************************************** */
static bool	isSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf")
		return (1);
	if (str == "+inf" || str == "+inff")
		return (1);
	if (str == "-inf" || str == "-inff")
		return (1);
	return (0);
}

/* ************************************************************************** */
static bool	isChar(const std::string& str, size_t& len)
{
	if (len == 3 && (str[1] >= 33 && str[1] <= 126) && (str[0] == '\'' && str[2] == '\''))
		return (1);
	if (len == 1 && (str[0] >= 33 && str[0] <= 126) && !(std::isdigit(str[0])))
		return (1);
	return (0);
}

/* ************************************************************************** */
static bool	isFloat(const std::string& str, size_t& len)
{
	size_t	index;
	size_t	dot;

	if(str[len - 1] != 'f')
		return (0);
	dot = str.find('.');
	if (dot == std::string::npos)
		return (0);
	index = 0;
	if (str[index] == '-')
		index++;
	if (str[index] == '.') // "-.123f"とかを弾く。".123f"とかも弾く。
		return (0);
	while (index != dot)
	{
		if (!(std::isdigit(str[index++])))
			return (0);
	}
	// str[index] == '.'　なう。
	index++;
	if(str[index] == 'f') // "123.f"とかだめよん。
		return (0);
	while(index != len - 1)
	{
		if (!(std::isdigit(str[index++])))
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
static bool	isDouble(const std::string& str, size_t& len)
{
	size_t	index;
	size_t	dot;

	dot = str.find('.');
	if (dot == std::string::npos)
		return (0);
	index = 0;
	if (str[index] == '-')
		index++;
	if (str[index] == '.') // "-.123"とかを弾く。".123"とかも弾く。
		return (0);
	while (index != dot)
	{
		if (!(std::isdigit(str[index++])))
			return (0);
	}
	// str[index] == '.'　なう。
	index++;
	while(index != len)
	{
		if (!(std::isdigit(str[index++])))
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
static bool	isInt(const std::string& str)
{
	int index;

	index = 0;
	if (str[index] == '-')
		index++;
	while ((str[index]) != '\0')
	{
		if (!(std::isdigit(str[index++])))
			return (0);
	}
	return (1);
}

/* ************************************************************************** */
e_type  whichType(const std::string& str, size_t& len)
{
	if (isSpecial(str))
		return SPECIAL;
	if (isChar(str, len))
		return CHAR;
	if (isFloat(str, len))
		return FLOAT;
	if (isDouble(str, len))
		return DOUBLE;
    if (isInt(str))
        return INT;
    return INVALID;
}
