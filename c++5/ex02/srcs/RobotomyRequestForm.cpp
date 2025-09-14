#include "../includes/RobotomyRequestForm.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form

RobotomyRequestForm::RobotomyRequestForm() 
	: AForm("RobotomyRequestForm", 72, 45), _target("default")
{
	std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target)
	: AForm("robotomy request", 72, 45), _target(target)
{
	std::cout << "RobotomyRequestForm parameterized constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src)
	: AForm(src), _target(src._target)
{
	std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs)
{
	std::cout << "RobotomyRequestForm copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

/* ************************************************************************** */
// ゲッター

const std::string&	RobotomyRequestForm::getTarget() const
{
	return (_target);
}

/* ************************************************************************** */
// 純粋仮想関数の実装

void	RobotomyRequestForm::executeAction() const
{
	// ドリル音
	std::cout << "**DRILLING NOISES**" << std::endl;
	
	// 乱数シードを現在時刻で設定（静的変数で一度だけ実行・・・シードが毎回同じだと、同じ結果になっちゃうからね。）
	static bool seeded = false;
	if (!seeded)
	{
		std::srand(std::time(NULL));
		seeded = true;
	}
	
	// 50%の確率で成功
	if (std::rand() % 2 == 0)
	{
		std::cout << _target << "\033[31m has been robotomized successfully!\033[m" << std::endl;
	}
	else
	{
		std::cout << "\033[31mThe robotomy of " << _target << " has failed!\033[m" << std::endl;
	}
}
