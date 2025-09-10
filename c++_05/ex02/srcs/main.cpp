#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"

int	main()
{
	// テスト1: ShrubberyCreationForm - 成功ケース
	try
	{
		std::cout << "=== Test 1: ShrubberyCreationForm (Success) ===" << std::endl;
		Bureaucrat			gardener("Gardener", 100);
		ShrubberyCreationForm	shrub("home");
		
		std::cout << shrub << std::endl;
		gardener.signAForm(shrub);
		gardener.executeAForm(shrub);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// テスト2: RobotomyRequestForm - 成功ケース  
	try
	{
		std::cout << "=== Test 2: RobotomyRequestForm (Success) ===" << std::endl;
		Bureaucrat			surgeon("Surgeon", 40);
		RobotomyRequestForm	robotomy("Bender");
		
		std::cout << robotomy << std::endl;
		surgeon.signAForm(robotomy);
		surgeon.executeAForm(robotomy);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// テスト3: PresidentialPardonForm - 成功ケース
	try
	{
		std::cout << "=== Test 3: PresidentialPardonForm (Success) ===" << std::endl;
		Bureaucrat			president("President", 1);
		PresidentialPardonForm	pardon("Ford Prefect");
		
		std::cout << pardon << std::endl;
		president.signAForm(pardon);
		president.executeAForm(pardon);
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// テスト4: 署名グレード不足
	try
	{
		std::cout << "=== Test 4: Sign Grade Too Low ===" << std::endl;
		Bureaucrat			intern("Intern", 150);
		PresidentialPardonForm	pardon("Arthur Dent");
		
		std::cout << pardon << std::endl;
		intern.signAForm(pardon);  // 失敗するはず
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// テスト5: 実行グレード不足
	try
	{
		std::cout << "=== Test 5: Execute Grade Too Low ===" << std::endl;
		Bureaucrat			signer("Signer", 20);
		Bureaucrat			executor("Executor", 100);
		PresidentialPardonForm	pardon("Marvin");
		
		std::cout << pardon << std::endl;
		signer.signAForm(pardon);    // 署名は成功
		executor.executeAForm(pardon); // 実行は失敗
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// テスト6: 署名されていないフォームの実行
	try
	{
		std::cout << "=== Test 6: Execute Unsigned Form ===" << std::endl;
		Bureaucrat			exec("Executive", 1);
		ShrubberyCreationForm	shrub("garden");
		
		std::cout << shrub << std::endl;
		exec.executeAForm(shrub);  // 署名していないので失敗
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// テスト7: 複数のrobotomy実行（50%確率のテスト）
	try
	{
		std::cout << "=== Test 7: Multiple Robotomy (50% Success Rate) ===" << std::endl;
		Bureaucrat			surgeon("ChiefSurgeon", 40);
				
		std::string targets[] = {"Target1", "Target2", "Target3", "Target4", "Target5"};

		for (int i = 0; i < 5; i++)
		{
			RobotomyRequestForm robotomy(targets[i]);
			surgeon.signAForm(robotomy);
			surgeon.executeAForm(robotomy);
			std::cout << std::endl;
		}
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// テスト8: 無効なグレードでのフォーム作成
	try
	{
		std::cout << "=== Test 8: Invalid Form Grade ===" << std::endl;
		ShrubberyCreationForm	invalid("test");  // これは問題ない
		// AForm invalidForm("Invalid", 0, 10);  // これは抽象クラスなので直接作成不可
		std::cout << "ShrubberyCreationForm created successfully" << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// テスト9: 全てのフォームタイプの確認
	try
	{
		std::cout << "=== Test 9: All Form Types Display ===" << std::endl;
		ShrubberyCreationForm	shrub("park");
		RobotomyRequestForm		robot("R2-D2");
		PresidentialPardonForm	pardon("Zaphod");
		
		std::cout << "Shrubbery: " << shrub << std::endl;
		std::cout << "Robotomy: " << robot << std::endl;
		std::cout << "Presidential: " << pardon << std::endl;
		std::cout << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "=== All tests completed ===" << std::endl;
	return (0);
}