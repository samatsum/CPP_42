#include "../includes/Intern.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern& src)
{
	std::cout << "Intern copy constructor called" << std::endl;
	*this = src;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern& rhs)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	(void)rhs;
	return (*this);
}

/* ************************************************************************** */
// フォーム作成関数

AForm*	Intern::createShrubberyForm(const std::string& target)
{
	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createRobotomyForm(const std::string& target)
{
	return (new RobotomyRequestForm(target));
}

AForm*	Intern::createPresidentialForm(const std::string& target)
{
	return (new PresidentialPardonForm(target));
}

/* ************************************************************************** */
AForm*	Intern::makeForm(const std::string& formName, const std::string& target)
{
	// フォーム名の配列
	const std::string formNames[3] = {
		"shrubbery creation",
		"robotomy request", 
		"presidential pardon"
	};
	
	// 対応する作成関数のポインタ配列
	FormCreator creators[3] = {
		&Intern::createShrubberyForm,
		&Intern::createRobotomyForm,
		&Intern::createPresidentialForm
	};
	
	// フォーム名を検索してフォーム作成
	for (int i = 0; i < 3; i++)
	{
		if (formName == formNames[i])
		{
			std::cout << "\033[32m Intern creates \033[m" << formName << std::endl;
			return ((this->*creators[i])(target));
		}
	}
	
	// 見つからなかった場合
	std::cout << "\033[31m Error: Unknown Form Name \033[m" << std::endl;
	return (NULL);
}
