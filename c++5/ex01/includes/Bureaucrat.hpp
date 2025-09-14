#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Form;  // 前方宣言

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;

public:
	// Orthodox Canonical Form
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat& rhs);

	// ゲッター
	const std::string&	getName() const;
	int					getGrade() const;

	// グレード操作
	void	incrementGrade();
	void	decrementGrade();

	// フォーム関連（追加）
	void	signForm(Form& form);

	// カスタム例外クラス
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

// 出力演算子のオーバーロード
std::ostream&	operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
