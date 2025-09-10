#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat;  // 前方宣言

class AForm
{
private:
	const std::string	_name;
	bool				_isSigned;
	const int			_gradeToSign;
	const int			_gradeToExecute;

public:
	// Orthodox Canonical Form
	AForm();
	AForm(const std::string& name, int gradeToSign, int gradeToExecute);
	AForm(const AForm& src);
	virtual ~AForm();  // 仮想デストラクタ（継承用）
	AForm&	operator=(const AForm& rhs);

	// ゲッター
	const std::string&	getName() const;
	bool				getIsSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExecute() const;

	// メンバ関数
	void			beSigned(const Bureaucrat& bureaucrat);
	void			execute(const Bureaucrat& executor) const;

	// 純粋仮想関数（サブクラスで必須実装）
	virtual void	executeAction() const = 0;

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

	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char*	what() const throw();
	};
};

// 出力演算子のオーバーロード
std::ostream&	operator<<(std::ostream& os, const AForm& form);

#endif