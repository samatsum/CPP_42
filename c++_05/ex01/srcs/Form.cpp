#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

/* ************************************************************************** */
// Orthodox Canonical Form

Form::Form() 
	: _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	
	// グレードの妥当性チェック
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form& src)
	: _name(src._name), _isSigned(src._isSigned), 
	  _gradeToSign(src._gradeToSign), _gradeToExecute(src._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

Form&	Form::operator=(const Form& rhs)
{
	std::cout << "Form copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// constメンバは代入できないので、_isSignedのみコピー
		_isSigned = rhs._isSigned;
	}
	return (*this);
}

/* ************************************************************************** */
// ゲッター

const std::string&	Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

/* ************************************************************************** */
// メンバ関数

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

/* ************************************************************************** */
// 例外クラスの実装

const char*	Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high!");
}

const char*	Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low!");
}

/* ************************************************************************** */
// 出力演算子

std::ostream&	operator<<(std::ostream& os, const Form& form)
{
	os << "Form " << form.getName() 
	   << ", signed: " << (form.getIsSigned() ? "yes" : "no")
	   << ", grade to sign: " << form.getGradeToSign()
	   << ", grade to execute: " << form.getGradeToExecute();
	return (os);
}
