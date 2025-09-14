#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "AForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
public:
	// Orthodox Canonical Form
	Intern();
	Intern(const Intern& src);
	~Intern();
	Intern&	operator=(const Intern& rhs);

	// メイン機能
	AForm*	makeForm(const std::string& formName, const std::string& target);

private:
	// フォーム作成関数のポインタ型定義
	typedef AForm* (Intern::*FormCreator)(const std::string& target);
	
	// 各フォーム作成関数
	AForm*	createShrubberyForm(const std::string& target);
	AForm*	createRobotomyForm(const std::string& target);
	AForm*	createPresidentialForm(const std::string& target);
};

#endif