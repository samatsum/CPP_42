#include "../includes/ScalarConverter.hpp"

/* ************************************************************************** */
static bool	onlyZero(const std::string& str, size_t len, size_t dot_pos)
{
	if (str[len - 1] == 'f')
		len--;
	size_t i = dot_pos + 1;
	while (i < len)
	{
		if (str[i++] != '0')
			return (false);
	}
	return (true);
}

/* ************************************************************************** */
void	convertSpecial(const std::string& str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char  : impossible" << std::endl; 
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char  : impossible" << std::endl;
		std::cout << "int   : impossible" << std::endl;
		std::cout << "float : -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

/* ************************************************************************** */
void	convertChar(const std::string& str)
{
	int targetIndex;

	targetIndex = 0;
	if (str[0] == '\'' && str[2] == '\'')
		targetIndex = 1;
	if (str[targetIndex] >= 33 && str[targetIndex] <= 126)
	{
		std::cout << "char  :'" << str[targetIndex] << "'" << std::endl;
		std::cout << "int   :" << static_cast<int>(str[targetIndex]) << std::endl;
		std::cout << "float :" << static_cast<float>(str[targetIndex]) << ".0f" << std::endl;
		std::cout << "double:" << static_cast<double>(str[targetIndex]) << ".0" << std::endl;
	}
	else
		std::cout<< "char  :Non displayable" << std::endl;
}

/* ************************************************************************** */
void	convertInt(const std::string& str)
{
	long	i = std::atol(str.c_str());

	if (i < 0 || i > 127)
		std::cout << "char  :impossible" << std::endl;
	else
	{
		if (i >= 33 && i <= 126)
			std::cout << "char  :'" << static_cast<char>(i) << "'" << std::endl;
		else
			std::cout << "char  :Non displayable" << std::endl;
	}
	if (i < INT_MIN || i > INT_MAX)
		std::cout << "int   :impossible" << std::endl;
	else
		std::cout << "int   :" << static_cast<int>(i) << std::endl;
	std::cout << "float :" << static_cast<float>(i) << ".0f" << std::endl;
	std::cout << "double:" << static_cast<double>(i) << ".0" << std::endl;
}

/* ************************************************************************** */
// fixed + setprecision(n) = 小数点以下n桁で固定表示
void	convertFloat(const std::string& str, size_t len)
{
	size_t	dot_pos = str.find('.');
	double	f = std::atof(str.c_str());
	bool	decimalPlacesZero = onlyZero(str, len, dot_pos); 

	if (decimalPlacesZero)//小数点以下全て０ならよぉ〜それは整数部だけが有効桁数ってことじゃねーのかぁ！？
		len = dot_pos + 2; // '.'と'f'で＋２。
	if (f < 0 || f > 127 || decimalPlacesZero == false)
		std::cout << "char  :impossible" << std::endl;
	else
	{
		if (f >= 33 && f <= 126)
			std::cout << "char  :'" << static_cast<char>(f) << "'" << std::endl;
		else 
			std::cout << "char  :Non displayable" << std::endl;
	}
	if (f < INT_MIN || f > INT_MAX)
		std::cout << "int   :impossible" << std::endl;
	else
		std::cout << "int   :" << static_cast<int>(f) << std::endl;
	if ((f < FLT_MIN && f > -FLT_MIN) || (f > FLT_MAX || f < -FLT_MAX))
		std::cout << "float :impossible" << std::endl;
	else
	{
		// 42.000001fが42Tokyo環境でのfloat精度限界だよん（8桁の数）。これ以上の桁数の数はdoubleでやりな。
		if (len >= 10)
			std::cout << "Attention : Float's Number of digits Overed 8 !!!" << std::endl;
		if (decimalPlacesZero)
			std::cout << "float :" << std::fixed << std::setprecision(1) << static_cast<float>(f) << "f" << std::endl;
		else
			std::cout << "float :" << std::fixed << std::setprecision(len - 2 - dot_pos) << static_cast<float>(f) << "f" << std::endl;
	}
	if ((f < DBL_MIN && f > -DBL_MIN) || (f > DBL_MAX || f < -DBL_MAX))
		std::cout << "double:impossible" << std::endl;
	else
	{
		// 42.00000000000001が42Tokyo環境でのdouble精度限界だよん（15桁の数）。
		if (len >= 18)
				std::cout << "Attention : Double's Number of digits Overed 15 !!!" << std::endl;
		if (decimalPlacesZero)
			std::cout << "double:" << std::fixed << std::setprecision(1) << static_cast<double>(f) << std::endl;
		else
			std::cout << "double:" << std::fixed << std::setprecision(len - 2 - dot_pos) << static_cast<double>(f) << std::endl;
	}
}

/* ************************************************************************** */
void	convertDouble(const std::string& str, size_t len)
{
	size_t		dot_pos = str.find('.');
	long double	d = std::atof(str.c_str());
	bool		decimalPlacesZero = onlyZero(str, len, dot_pos); 

	if (decimalPlacesZero)//小数点以下全て０ならよぉ〜それは整数部だけが有効桁数ってことじゃねーのかぁ！？
		len = dot_pos + 1;// '.'で＋１。
	if (d < 0 || d > 127 || decimalPlacesZero == false)
		std::cout << "char  :impossible" << std::endl;
	else
	{
		if (d >= 33 && d <= 126)
			std::cout << "char  :'" << static_cast<char>(d) << "'" << std::endl;
		else 
			std::cout << "char  :Non displayable" << std::endl;
	}
	
	if (d < INT_MIN || d > INT_MAX)
		std::cout << "int   :impossible" << std::endl;
	else
		std::cout << "int   :" << static_cast<int>(d) << std::endl;
	
	if ((d < FLT_MIN && d > -FLT_MIN) || (d > FLT_MAX || d < -FLT_MAX))
		std::cout << "float :impossible" << std::endl;
	else
	{
		// 42.00001fが42Tokyo環境でのfloat精度限界だよん（8桁の数）。これ以上の桁数の数はdoubleでやりな。
		if (len >= 9)
			std::cout << "Attention : Float's Number of digits Overed 8 !!!" << std::endl;
		if (decimalPlacesZero)
			std::cout << "float :" << std::fixed << std::setprecision(1) << static_cast<float>(d) << "f" << std::endl;
		else 
			std::cout << "float :" << std::fixed << std::setprecision(len - 1 - dot_pos) << static_cast<float>(d) << "f" << std::endl;
	}
	
	if ((d < DBL_MIN && d > -DBL_MIN) || (d > DBL_MAX || d < -DBL_MAX))
		std::cout << "double:impossible" << std::endl;
	else
	{
		// 42.00000000000001が42Tokyo環境でのdouble精度限界だよん（15桁の数）。
		if (len >= 17)
			std::cout << "Attention : Double's Number of digits Overed 15 !!!" << std::endl;
		if (decimalPlacesZero)
			std::cout << "double:" << std::fixed << std::setprecision(1) << d << std::endl;
		else
			std::cout << "double:" << std::fixed << std::setprecision(len - 1 - dot_pos) << d << std::endl;
	}
}
