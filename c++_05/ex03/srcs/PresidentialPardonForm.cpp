#include "../includes/PresidentialPardonForm.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form

PresidentialPardonForm::PresidentialPardonForm() 
	: AForm("PresidentialPardonForm", 25, 5), _target("default")
{
	std::cout << "PresidentialPardonForm default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target)
	: AForm("presidential pardon", 25, 5), _target(target)
{
	std::cout << "PresidentialPardonForm parameterized constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src)
	: AForm(src), _target(src._target)
{
	std::cout << "PresidentialPardonForm copy constructor called" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs)
{
	std::cout << "PresidentialPardonForm copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		AForm::operator=(rhs);
		_target = rhs._target;
	}
	return (*this);
}

/* ************************************************************************** */
// ゲッター

const std::string&	PresidentialPardonForm::getTarget() const
{
	return (_target);
}

/* ************************************************************************** */
// 純粋仮想関数の実装

void	PresidentialPardonForm::executeAction() const
{
	std::cout << _target << "\033[31m has been pardoned by Zaphod Beeblebrox.\033[m" << std::endl;
}
