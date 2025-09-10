#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;  // 前方宣言

class Form
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	// Orthodox Canonical Form
	Form();
	Form(const std::string& name, int gradeToSign, int gradeToExecute);
	Form(const Form& src);
	~Form();
	Form&	operator=(const Form& rhs);

	// ゲッター
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// メンバ関数
	void	beSigned(const Bureaucrat& bureaucrat);

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
std::ostream&	operator<<(std::ostream& os, const Form& form);

#endif
