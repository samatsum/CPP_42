#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

/* ************************************************************************** */
Bureaucrat::Bureaucrat() : _name("default"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name)
{
	std::cout << "Bureaucrat parameterized constructor called" << std::endl;
	
	// グレードの妥当性チェック
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& rhs)
{
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		// _nameはconstなので代入できない
		_grade = rhs._grade;
	}
	return (*this);
}

/* ************************************************************************** */
// ゲッター

const std::string&	Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

/* ************************************************************************** */
// グレード操作

void	Bureaucrat::incrementGrade()
{
	// グレード1が最高なので、インクリメントは数値を減らす
	if (_grade - 1 < 1)
		throw GradeTooHighException();
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	// グレード150が最低なので、デクリメントは数値を増やす
	if (_grade + 1 > 150)
		throw GradeTooLowException();
	_grade++;
}

/* ************************************************************************** */
// 例外クラスの実装

const char*	Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char*	Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

/* ************************************************************************** */
// 出力演算子

std::ostream&	operator<<(std::ostream& output_stream, const Bureaucrat& bureaucrat)
{
	output_stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return output_stream;
}

/* ************************************************************************** */
// フォーム関連（追加）

void	Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() 
				  << " because " << e.what() << std::endl;
	}
}
