#include "../includes/iter.hpp"
#include <iostream>
#include <string>
#include <cctype>

// ===== 非const参照を受け取る関数（値を変更） =====
void increment_int(int &value)
{
    value++;
}

// ===== const参照を受け取る関数（読み取り専用） =====
void print_int(const int &value)
{
    std::cout << value << " ";
}

/* ************************************************************************** */
int main()
{
    std::cout << "=== CPP07 Exercise 01: iter function template ===" << std::endl;
    
    // ===== テスト2: int配列での変更操作 =====
    std::cout << "\n--- Test 2: int array modification ---" << std::endl;
    int int_array[] = {1, 2, 3};
    size_t int_size = sizeof(int_array) / sizeof(int);
    
    std::cout << "Non-Const Array: ";
    ::iter(int_array, int_size, print_int);
    std::cout << std::endl;
    
    ::iter(int_array, int_size, increment_int);
    std::cout << "After increment: ";
    ::iter(int_array, int_size, print_int);
    std::cout << std::endl;
    
    // ===== テスト3: const配列（読み取り専用） =====
    std::cout << "\n--- Test 3: const array (read-only) ---" << std::endl;
    const int const_array[] = {10, 20, 30};
    size_t const_size = sizeof(const_array) / sizeof(int);
    std::cout << "Const array: ";
    ::iter(const_array, const_size, print_int);  // const版のiterが呼ばれる
	//::iter(const_array, const_size, increment_int); ここはエラーになる。
	// std::cout << "After increment: ";
    // ::iter(int_array, int_size, print_int);
    std::cout << std::endl;
    
    std::cout << "\n=== All tests completed successfully! ===" << std::endl;
    
    return 0;
}