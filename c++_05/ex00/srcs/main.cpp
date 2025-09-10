#include "../includes/Bureaucrat.hpp"
/* ************************************************************************** */
int	main()
{
	// テスト1: 正常な生成
	try
	{
		std::cout << "=== Test 1: Valid creation ===" << std::endl;
		Bureaucrat	bob("Bob", 75);
		std::cout << bob << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト2: グレードが高すぎる（0以下）
	try
	{
		std::cout << "=== Test 2: Grade too high ===" << std::endl;
		Bureaucrat	alice("Alice", 0);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト3: グレードが低すぎる（151以上）
	try
	{
		std::cout << "=== Test 3: Grade too low ===" << std::endl;
		Bureaucrat	charlie("Charlie", 151);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト4: インクリメント・デクリメントのテスト
	try
	{
		std::cout << "=== Test 4: Increment/Decrement ===" << std::endl;
		Bureaucrat	dave("Dave", 2);
		std::cout << dave << std::endl;
		
		dave.incrementGrade();
		std::cout << "After increment: " << dave << std::endl;
		
		dave.incrementGrade();  // これは例外を投げるはず
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl;

	// テスト5: コピーコンストラクタのテスト
	try
	{
		std::cout << "=== Test 5: Copy constructor ===" << std::endl;
		Bureaucrat	original("Original", 42);
		Bureaucrat	copy(original);
		std::cout << "Original: " << original << std::endl;
		std::cout << "Copy: " << copy << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return (0);
}
