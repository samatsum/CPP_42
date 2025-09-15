#include "../includes/ScalarConverter.hpp"

/* ************************************************************************** */
ScalarConverter::ScalarConverter(void)
{
    std::cout << "ScalerConverter default constructor called" << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
    std::cout << "ScalerConverter copy constructor called" << std::endl;
    *this = src;
}

ScalarConverter	&ScalarConverter::operator=(ScalarConverter const &rhs)
{
    std::cout << "ScalerConverter copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

ScalarConverter::~ScalarConverter(void)
{
    std::cout << "ScalerConverter destructer called" << std::endl;
}

/* ************************************************************************** */
void    ScalarConverter::convert(const std::string& str)
{
    size_t  len = str.length();
    e_type  type = whichType(str, len);
    switch(type)
    {
        case INVALID:
            std::cout << "\033[31m Please enter a Correct value\033[m" << std::endl;
            std::cout << "Char: 'a','b','c',...(ASCII参照)" << std::endl;
            std::cout << "Int: 1,2,3,...2147483647...-1,-2,-3,...-2147483648" << std::endl;
            std::cout << "Float: 0.0f, -4.2f, 4.2f,...-inff, +inff, nanf" << std::endl;
            std::cout << "Double: 0.0, -4.2, 4.2,...-inf, +inf, nan" << std::endl;
            break;
        case SPECIAL:
            convertSpecial(str);
            break;
        case CHAR:
            convertChar(str);
            break;
        case FLOAT:
            convertFloat(str, len);
            break;
        case DOUBLE:
            convertDouble(str, len);
            break;
        case INT:
            convertInt(str);
            break;
    }
}
