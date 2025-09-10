#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"

int	main()
{
	// テスト1: 正常なフォーム作成
	try
	{
		std::cout << "=== Test 1: Valid form creation ===" << std::endl;
		Form	taxForm("Tax Form", 25, 10);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト2: 無効なグレードでのフォーム作成
	try
	{
		std::cout << "=== Test 2: Invalid grade (too high) ===" << std::endl;
		Form	invalidForm("Invalid Form", 0, 10);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト3: 無効なグレードでのフォーム作成（低すぎる）
	try
	{
		std::cout << "=== Test 3: Invalid grade (too low) ===" << std::endl;
		Form	invalidForm2("Invalid Form 2", 25, 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト4: フォームへの署名（成功）
	try
	{
		std::cout << "=== Test 4: Successful signing ===" << std::endl;
		Bureaucrat	highRank("CEO", 5);
		Form		contract("Employment Contract", 10, 5);
		
		std::cout << contract << std::endl;
		highRank.signForm(contract);
		std::cout << contract << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト5: フォームへの署名（失敗）
	try
	{
		std::cout << "=== Test 5: Failed signing ===" << std::endl;
		Bureaucrat	lowRank("Intern", 100);
		Form		secretDoc("Secret Document", 10, 5);
		
		std::cout << secretDoc << std::endl;
		lowRank.signForm(secretDoc);
		std::cout << secretDoc << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト6: 同じフォームに複数回署名
	try
	{
		std::cout << "=== Test 6: Multiple signatures ===" << std::endl;
		Bureaucrat	manager("Manager", 20);
		Form		report("Monthly Report", 30, 25);
		
		manager.signForm(report);
		manager.signForm(report);  // 既に署名済み
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}