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
    size_t  len = str.length(); //文字数
    e_type  type = whichType(str, len);
    switch(type)
    {
        case INVALID:
            std::cout << "Invalid input" << std::endl;
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
