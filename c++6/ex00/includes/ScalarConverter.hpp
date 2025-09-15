#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <limits>
# include <cmath>
# include <float.h>
# include <cfloat>
# include <stdio.h>
# include <climits>
# include <iostream>
# include <iomanip>
# include <exception>
# include <cstdlib>

enum    e_type
{
	INVALID = -1,
    SPECIAL = 0,
    CHAR = 1,
    INT = 2,
    FLOAT = 3,
    DOUBLE = 4
};

class	ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter(void);
		ScalarConverter	&operator=(ScalarConverter const &rhs);
	public:
		static void	convert(const std::string& str);
};

e_type	whichType(const std::string& str, size_t& len);
void	convertSpecial(const std::string& str);
void	convertChar(const std::string& str);
void	convertInt(const std::string& str);
void	convertFloat(const std::string& str, size_t len);
void	convertDouble(const std::string& str, size_t len);

#endif
