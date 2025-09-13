#include "../includes/ShrubberyCreationForm.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form

ShrubberyCreationForm::ShrubberyCreationForm() 
	: AForm("ShrubberyCreationForm", 145, 137), _target("default")
{
	std::cout << "ShrubberyCreationForm default constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("shrubbery creation", 145, 137), _target(target)
{
	std::cout << "ShrubberyCreationForm parameterized constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
	: AForm(src), _target(src._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	std::cout << "ShrubberyCreationForm copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

/* ************************************************************************** */
// ゲッター

const std::string&	ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

/* ************************************************************************** */
// 純粋仮想関数の実装

void	ShrubberyCreationForm::executeAction() const
{
	std::string	filename = _target + "_shrubbery";
	std::ofstream	file(filename.c_str());
	
	if (!file.is_open())
	{
		std::cout << "\033[31mError: Could not create file \033[m" << filename << std::endl;
		return ;
	}

	// ASCII Trees by ChatGPT SENSEI!!!
	file << "                                              ." << std::endl;
	file << "                                   .         ;  " << std::endl;
	file << "      .              .              ;%     ;;   " << std::endl;
	file << "        ,           ,                :;%  %;   " << std::endl;
	file << "         :         ;                   :;%;'     .,   " << std::endl;
	file << ",.        %;     %;            ;        %;'    ,;" << std::endl;
	file << "  ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
	file << "   %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
	file << "    ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
	file << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
	file << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
	file << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
	file << "           `@%:.  :;%.         ;@@%;'   " << std::endl;
	file << "             `@%.  `;@%.      ;@@%;         " << std::endl;
	file << "               `@%%. `@%%    ;@@%;        " << std::endl;
	file << "                 ;@%. :@%%  %@@%;       " << std::endl;
	file << "                   %@bd%%%bd%%:;     " << std::endl;
	file << "                     #@%%%%%:;;" << std::endl;
	file << "                     %@@%%%::;" << std::endl;
	file << "                     %@@@%(o);  . '         " << std::endl;
	file << "                     %@@@o%;:(.,'         " << std::endl;
	file << "                 `.. %@@@o%::;         " << std::endl;
	file << "                    `)@@@o%::;         " << std::endl;
	file << "                     %@@(o)::;        " << std::endl;
	file << "                    .%@@@@%::;         " << std::endl;
	file << "                    ;%@@@@%::;.          " << std::endl;
	file << "                   ;%@@@@%%:;;;. " << std::endl;
	file << "               ...;%@@@@@%%:;;;;,.." << std::endl;

	file.close();
	std::cout << "\033[32mASCII trees have been planted in \033[m" << filename << std::endl;
}
