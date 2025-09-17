#include "../includes/easyfind.hpp"

/* ************************************************************************** */
//std::vector と std::list はどちらも シーケンスコンテナ
int main()
{
	std::cout << "=== Testing with std::vector ===" << std::endl;
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	// 成功ケースでインデックスを取得
	try {
		std::vector<int>::iterator result_it = easyfind(vec, 3);
		
		// イテレータからインデックスを計算
		long index = std::distance(vec.begin(), result_it);
		
		std::cout << "Found: " << *result_it << " at index: " << index << std::endl;
	} catch (const NoOccurrenceFoundException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	try {
		std::vector<int>::iterator result_it = easyfind(vec, 42);
		
		// イテレータからインデックスを計算
		long index = std::distance(vec.begin(), result_it);
		
		std::cout << "Found: " << *result_it << " at index: " << index << std::endl;
	} catch (const NoOccurrenceFoundException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	// std::list でのテスト
	std::cout << "\n=== Testing with std::list ===" << std::endl;
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	// 成功
	try {
		std::list<int>::iterator result = easyfind(lst, 20);
		long index = std::distance(lst.begin(), result);
		std::cout << "Found: " << *result << " at index: " << index << std::endl;
	} catch (const NoOccurrenceFoundException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	// 失敗
	try {
		std::list<int>::iterator result = easyfind(lst, 42);
		std::cout << "Found: " << *result << std::endl;
	} catch (const NoOccurrenceFoundException& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}