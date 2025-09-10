#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>

class Bureaucrat
{
private:
	const std::string	_name;
	int					_grade;  // 1が最高、150が最低

public:
	Bureaucrat();
	Bureaucrat(const std::string& name, int grade);
	Bureaucrat(const Bureaucrat& src);
	~Bureaucrat();
	Bureaucrat&	operator=(const Bureaucrat& rhs);

	// ゲッター
	const std::string&	getName() const;
	int					getGrade() const;

	// グレード操作
	void	incrementGrade();  // グレードを上げる（数値は減る）
	void	decrementGrade();  // グレードを下げる（数値は増える）

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