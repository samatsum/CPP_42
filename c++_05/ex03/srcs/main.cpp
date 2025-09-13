#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/Intern.hpp"

int	main()
{
	// 乱数シードを最初に設定（ロボトミー用）
	std::srand(std::time(NULL));
	std::cout << std::endl;

	// テスト1: Intern による ShrubberyCreationForm 作成と実行
	try
	{
		std::cout << "=== Test 1: Intern creates ShrubberyCreationForm ===" << std::endl;
		Intern		intern;
		AForm*		form;
		Bureaucrat	bureaucrat("Gardener", 100);
		
		form = intern.makeForm("shrubbery creation", "garden");
		if (form)
		{
			std::cout << *form << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// テスト2: Intern による RobotomyRequestForm 作成と実行
	try
	{
		std::cout << "=== Test 2: Intern creates RobotomyRequestForm ===" << std::endl;
		Intern		intern;
		AForm*		form;
		Bureaucrat	bureaucrat("Surgeon", 40);
		
		form = intern.makeForm("robotomy request", "Bender");
		if (form)
		{
			std::cout << *form << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// テスト3: Intern による PresidentialPardonForm 作成と実行
	try
	{
		std::cout << "=== Test 3: Intern creates PresidentialPardonForm ===" << std::endl;
		Intern		intern;
		AForm*		form;
		Bureaucrat	bureaucrat("President", 1);
		
		form = intern.makeForm("presidential pardon", "Ford Prefect");
		if (form)
		{
			std::cout << *form << std::endl;
			bureaucrat.signForm(*form);
			bureaucrat.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// テスト4: 存在しないフォーム名でのテスト
	try
	{
		std::cout << "=== Test 4: Unknown form name ===" << std::endl;
		Intern		intern;
		AForm*		form;
		
		form = intern.makeForm("unknown form", "target");
		if (form)
		{
			std::cout << "Form created unexpectedly!" << std::endl;
			delete form;
		}
		else
		{
			std::cout << "Form creation failed as expected." << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// テスト5: 複数のフォーム作成
	try
	{
		std::cout << "=== Test 5: Multiple form creation ===" << std::endl;
		Intern		intern;
		AForm*		forms[3];
		Bureaucrat	president("President", 1);
		
		forms[0] = intern.makeForm("shrubbery creation", "park");
		forms[1] = intern.makeForm("robotomy request", "C-3PO");
		forms[2] = intern.makeForm("presidential pardon", "Arthur Dent");
		
		for (int i = 0; i < 3; i++)
		{
			std::cout << "//////////////////////////////////////////////" <<std::endl;
			if (forms[i])
			{
				std::cout << *forms[i] << std::endl;
				president.signForm(*forms[i]);
				president.executeForm(*forms[i]);
				delete forms[i];
			}
			std::cout << "//////////////////////////////////////////////" <<std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// テスト6: 最低グレードでのテスト
	try
	{
		std::cout << "=== Test 6: Grade restriction test ===" << std::endl;
		Intern		intern;
		AForm*		form;
		Bureaucrat	lowGrade("Intern", 150);
		
		form = intern.makeForm("presidential pardon", "Zaphod");
		if (form)
		{
			std::cout << *form << std::endl;
			lowGrade.signForm(*form);    // 失敗するはず（２５は必要）
			lowGrade.executeForm(*form); // 失敗するはず（５は必要）
			delete form;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// テスト7: Internの複数インスタンス
	try
	{
		std::cout << "=== Test 7: Multiple Intern instances ===" << std::endl;
		Intern		intern1;
		Intern		intern2;
		Bureaucrat	bureaucrat("Worker", 50);
		
		AForm*		form1 = intern1.makeForm("shrubbery creation", "office");
		AForm*		form2 = intern2.makeForm("robotomy request", "robot");
		
		if (form1 && form2)
		{
			bureaucrat.signForm(*form1);
			bureaucrat.executeForm(*form1);
			
			bureaucrat.signForm(*form2);
			bureaucrat.executeForm(*form2);
			
			delete form1;
			delete form2;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;
	// テスト8: 課題のコード
	try
	{
		std::cout << "=== Test 8: Example from subject ===" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		if (rrf)
		{
			std::cout << "Form created successfully: " << *rrf << std::endl;
			delete rrf;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "=== All tests completed ===" << std::endl;
	return (0);
}
