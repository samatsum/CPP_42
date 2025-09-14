#include "../includes/ScalarConverter.hpp"

/* ************************************************************************** */
int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "\033[31m Please enter a Correct value\033[m" << std::endl;
        std::cout << "Char: 'a','b','c',...(ASCII参照)" << std::endl;
        std::cout << "Int: 1,2,3,...2147483647...-1,-2,-3,...-2147483648" << std::endl;
        std::cout << "Float: 0.0f, -4.2f, 4.2f,...-inff, +inff, nanf" << std::endl;
        std::cout << "Double: 0.0, -4.2, 4.2,...-inf, +inf, nan" << std::endl;
        std::cout << std::endl;
        
        std::cout << "=== Float の境界値 ===" << std::endl;
        std::cout << "正の最大値: " << FLT_MAX << "f" << std::endl;
        std::cout << "正の最小値: " << FLT_MIN << "f" << std::endl;// 0に最も近い正の値  
        std::cout << "負の最大値: " << -FLT_MIN << "f" << std::endl;// 0に最も近い負の値
        std::cout << "負の最小値: " << -FLT_MAX << "f" << std::endl;  
        std::cout << std::endl;
        
        std::cout << "=== Double の境界値 ===" << std::endl;
        std::cout << "正の最大値: " << DBL_MAX << std::endl;
        std::cout << "正の最小値: " << DBL_MIN << std::endl;
        std::cout << "負の最大値: " << -DBL_MIN << std::endl;
        std::cout << "負の最小値: " << -DBL_MAX << std::endl;
        std::cout << std::endl;
        std::cout << "Except for char parameters, only the decimal notation will be used.(科学的記数法（e記法）は考慮する必要がないよん。)" << std::endl;
        std::cout << "数字の'1'は、./Conversion_of_scalar_types \'1\'" << std::endl;
        std::cout << "数値の'1'は、./Conversion_of_scalar_types 1" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);

	return (0);
}
