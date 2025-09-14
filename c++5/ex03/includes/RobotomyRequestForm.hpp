#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
private:
	std::string	_target;

public:
	// Orthodox Canonical Form
	RobotomyRequestForm();
	RobotomyRequestForm(const std::string& target);
	RobotomyRequestForm(const RobotomyRequestForm& src);
	~RobotomyRequestForm();
	RobotomyRequestForm&	operator=(const RobotomyRequestForm& rhs);

	// ゲッター
	const std::string&	getTarget() const;

	// 純粋仮想関数のオーバーライド
	void	executeAction() const;
};

#endif