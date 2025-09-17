#include "../includes/MutantStack.hpp"

//std::stackはイテレータを提供しない。
//stackの内容を確認するためには、要素を一つずつtop()で取得してpop()で削除するしかない。
//stackは「後入先出（LIFO: Last In, First Out）」というデータ構造の抽象概念を表現しており、理論的には「最上位の要素のみにアクセス可能」
//std::stackは実際には「コンテナアダプタ」と呼ばれる設計パターンの実装であり、内部的には他のコンテナ（デフォルトではstd::deque）を使用しています。この内部コンテナにアクセスできれば、そのイテレータを活用することが可能。
/* ************************************************************************** */
int subject_test()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
	std::cout << *it << std::endl;
	++it;
	}
	std::stack<int> s(mstack);
	return 0;
}

/* ************************************************************************** */
// void my_test()
// {
// 	// Test with int
//     std::cout << YELLOW "\nTesting with int\n" RESET << std::endl;
//     MutantStack<int> intStack;
//     intStack.push(42);
//     intStack.push(-1);
//     intStack.push(2024);
//     intStack.push(0);

//     std::cout << BLUE "Iterating using non-const iterator:" RESET << std::endl;
//     for (MutantStack<int>::iterator it = intStack.begin(); it != intStack.end(); ++it) {
//         std::cout << *it << std::endl;
//     }

//     std::cout << BLUE"Iterating using const_iterator:" RESET << std::endl;
//     for (MutantStack<int>::const_iterator cit = intStack.begin(); cit != intStack.end(); ++cit) {
//         std::cout << *cit << std::endl;
//     }

//     // Test with std::string
//     std::cout << YELLOW  "\nTesting with std::string\n" RESET << std::endl;
//     MutantStack<std::string> stringStack;
//     stringStack.push("Check out");
//     stringStack.push("How my");
//     stringStack.push("MutantStack");
//     stringStack.push("is");
//     stringStack.push("awesome!");

// 	std::cout << BLUE "All elements:" RESET << std::endl;
//     for (MutantStack<std::string>::const_iterator it = stringStack.begin(); it != stringStack.end(); ++it)
//         std::cout << *it << " ";
// 	std::cout << std::endl;

//     std::cout << BLUE "Top element: " RESET << stringStack.top() << std::endl;
//     stringStack.pop();
//     std::cout << BLUE "Top after pop: " RESET << stringStack.top() << std::endl;
// 	std::cout << std::endl;

//     // Test with float
//     std::cout << YELLOW "\nTesting with float\n" RESET << std::endl;
//     MutantStack<float> floatStack;
//     floatStack.push(3.14f);
//     floatStack.push(1.618f);
//     floatStack.push(2.718f);
//     floatStack.push(1.414f);

//     std::cout << BLUE "All elements:" RESET << std::endl;
// 	for (MutantStack<float>::iterator it = floatStack.begin(); it != floatStack.end(); ++it)
// 		std::cout << (*it) << std::endl;
// 	std::cout << BLUE "\nIterating backwards:" RESET << std::endl;
//     MutantStack<float>::iterator ite = floatStack.end();
//     MutantStack<float>::iterator itb = floatStack.begin();
//     while (ite != itb) 
// 	{
//         --ite; // Move iterator backwards
//         std::cout << *ite << std::endl;
//         //if (ite == itb) break; // Check to avoid decrementing begin()
//     }

//     // Edge case: empty stack
//     std::cout << YELLOW "\nTesting edge case with empty MutantStack<int>" RESET << std::endl;
//     MutantStack<int> emptyStack;
//     std::cout << "Is stack empty? " << (emptyStack.empty() ? "Yes" : "No") << std::endl;
//     if (!emptyStack.empty()) {
//         std::cout << "Unexpected non-empty stack!" << std::endl;
//     }

//     // Copy constructor and assignment operator
//     std::cout << YELLOW "\nTesting copy and assignment (on Stack<int>)" RESET << std::endl;
//     MutantStack<int> copiedStack = intStack; // Copy constructor
//     MutantStack<int> assignedStack;
//     assignedStack = intStack; // Assignment operator

//     std::cout << "Copied stack size: " << copiedStack.size() << std::endl;
//     std::cout << "Assigned stack size: " << assignedStack.size() << std::endl;

	
// 	// last edge case : cannot access the deque of underlying container (we only typdef iterators, no deque::methods)
// 	MutantStack<int> mstack;
//     mstack.push(42);
    
//     // Uncommenting the following line should cause a compilation error : `front` is a deque-specific.
//     // int frontValue = mstack.front();
// }

/* ************************************************************************** */
int main()
{
	
	subject_test();
//	my_test();
	return 0;
}