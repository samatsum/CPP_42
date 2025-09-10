#include "../includes/AForm.hpp"
#include "../includes/Bureaucrat.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form

AForm::AForm() 
	: _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm parameterized constructor called" << std::endl;
	
	// グレードの妥当性チェック
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm& src)
	: _name(src._name), _isSigned(src._isSigned), 
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

AForm&	AForm::operator=(const AForm& rhs)
{
	std::cout << "AForm copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// constメンバは代入できないので、_isSignedのみコピー
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

/* ************************************************************************** */
// ゲッター

const std::string&	AForm::getName() const
{
	return (_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

/* ************************************************************************** */
// メンバ関数

void	AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	// 署名されているかチェック
	if (!_isSigned)
		throw FormNotSignedException();
	
	// 実行者のグレードチェック
	if (executor.getGrade() > _gradeToExecute)
		throw GradeTooLowException();
	
	// 実際の実行処理（サブクラスで実装）
	executeAction();
}

/* ************************************************************************** */
// 例外クラスの実装

const char*	AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char*	AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

const char*	AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

/* ************************************************************************** */
// 出力演算子

std::ostream&	operator<<(std::ostream& os, const AForm& form)
{
	os << "Form " << form.getName() 
	   << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return (os);
}