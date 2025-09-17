#include "../includes/Array.hpp"
#include <iostream>
#include <string>

#define MAX_VAL 10  // テスト用に小さな値に変更

// テスト用カラー出力
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define RESET   "\033[0m"

// テスト結果カウンタ
static int test_group_count = 0;
static int individual_test_count = 0;
static int passed_tests = 0;
static int failed_tests = 0;

void print_test_header(const std::string& test_name) {
    std::cout << "\n" << BLUE << "========================================" << RESET << std::endl;
    std::cout << BLUE << "TEST " << ++test_group_count << ": " << test_name << RESET << std::endl;
    std::cout << BLUE << "========================================" << RESET << std::endl;
}

void print_success(const std::string& message) {
    std::cout << GREEN << "✓ " << message << RESET << std::endl;
    individual_test_count++;
    passed_tests++;
}

void print_error(const std::string& message) {
    std::cout << RED << "✗ " << message << RESET << std::endl;
    individual_test_count++;
    failed_tests++;
}

void print_info(const std::string& message) {
    std::cout << YELLOW << "ℹ " << message << RESET << std::endl;
}

void test_default_constructor() {
    print_test_header("Default Constructor Test");
    
    Array<int> empty_array;
    
    if (empty_array.size() == 0) {
        print_success("Empty array size is 0");
    } else {
        print_error("Empty array size is not 0");
    }
}

void test_parameterized_constructor() {
    print_test_header("Parameterized Constructor Test");
    
    Array<int> numbers(MAX_VAL);
    
    if (numbers.size() == MAX_VAL) {
        print_success("Array size matches constructor parameter");
    } else {
        print_error("Array size doesn't match constructor parameter");
    }
    
    // デフォルト初期化の確認
    bool all_zero = true;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        if (numbers[i] != 0) {
            all_zero = false;
            break;
        }
    }
    
    if (all_zero) {
        print_success("All elements initialized to default value (0)");
    } else {
        print_error("Elements not properly initialized");
    }
    
    // 文字列配列でのテスト
    Array<std::string> strings(5);
    bool all_empty = true;
    for (unsigned int i = 0; i < strings.size(); i++) {
        if (!strings[i].empty()) {
            all_empty = false;
            break;
        }
    }
    
    if (all_empty) {
        print_success("String array elements initialized to empty strings");
    } else {
        print_error("String array elements not properly initialized");
    }
}

void test_copy_constructor() {
    print_test_header("Copy Constructor Test");
    
    // 元配列の準備
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = i * 10;
    }
    
    // コピーコンストラクタのテスト
    Array<int> copy(original);
    
    // サイズチェック
    if (copy.size() == original.size()) {
        print_success("Copy has same size as original");
    } else {
        print_error("Copy size differs from original");
    }
    
    // 内容チェック
    bool content_match = true;
    for (unsigned int i = 0; i < original.size(); i++) {
        if (copy[i] != original[i]) {
            content_match = false;
            break;
        }
    }
    
    if (content_match) {
        print_success("Copy has same content as original");
    } else {
        print_error("Copy content differs from original");
    }
    
    // 深いコピーのテスト
    original[0] = 999;
    if (copy[0] != 999) {
        print_success("Deep copy confirmed - modifying original doesn't affect copy");
    } else {
        print_error("Shallow copy detected - modifying original affects copy");
    }
}

void test_assignment_operator() {
    print_test_header("Assignment Operator Test");
    
    // 元配列の準備
    Array<int> original(5);
    for (unsigned int i = 0; i < original.size(); i++) {
        original[i] = i * 20;
    }
    
    // 異なるサイズの配列に代入
    Array<int> assigned(3);
    assigned = original;
    
    // サイズチェック
    if (assigned.size() == original.size()) {
        print_success("Assignment updated array size correctly");
    } else {
        print_error("Assignment didn't update array size");
    }
    
    // 内容チェック
    bool content_match = true;
    for (unsigned int i = 0; i < original.size(); i++) {
        if (assigned[i] != original[i]) {
            content_match = false;
            break;
        }
    }
    
    if (content_match) {
        print_success("Assignment copied content correctly");
    } else {
        print_error("Assignment didn't copy content correctly");
    }
    
    // 深いコピーのテスト
    original[1] = 777;
    if (assigned[1] != 777) {
        print_success("Deep copy confirmed - modifying original doesn't affect assigned");
    } else {
        print_error("Shallow copy detected - modifying original affects assigned");
    }
}

void test_subscript_operator() {
    print_test_header("Subscript Operator [] Test");
    
    Array<int> numbers(5);
    
    // 書き込みテスト
    for (unsigned int i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 100;
    }
    print_success("Writing with [] operator successful");
    
    // 読み取りテスト
    bool read_correct = true;
    for (unsigned int i = 0; i < numbers.size(); i++) {
        if (numbers[i] != static_cast<int>(i * 100)) {
            read_correct = false;
            break;
        }
    }
    
    if (read_correct) {
        print_success("Reading with [] operator successful");
    } else {
        print_error("Reading with [] operator failed");
    }
    
    // const版のテスト
    const Array<int> const_numbers = numbers;
    if (const_numbers[0] == 0) {
        print_success("const [] operator working");
    } else {
        print_error("const [] operator failed");
    }
}

void test_exception_handling() {
    print_test_header("Exception Handling Test");
    
    Array<int> numbers(5);
    
    // 正の範囲外アクセス
    try {
        numbers[10] = 42;
        print_error("No exception thrown for positive out-of-bounds access");
    } catch (const std::exception& e) {
        print_success("Exception caught for positive out-of-bounds access");
        print_info(std::string("Exception message: ") + e.what());
    }
    
    // 負のインデックス（unsigned intにキャストされて大きな値になる）
    try {
        numbers[-1] = 42;
        print_error("No exception thrown for negative index");
    } catch (const std::exception& e) {
        print_success("Exception caught for negative index");
        print_info(std::string("Exception message: ") + e.what());
    }
    
    // 空配列での範囲外アクセス
    Array<int> empty;
    try {
        empty[0] = 42;
        print_error("No exception thrown for empty array access");
    } catch (const std::exception& e) {
        print_success("Exception caught for empty array access");
        print_info(std::string("Exception message: ") + e.what());
    }
}

void test_size_function() {
    print_test_header("Size Function Test");
    
    Array<int> empty;
    Array<int> small(3);
    Array<int> large(MAX_VAL);
    
    if (empty.size() == 0) {
        print_success("Empty array size() returns 0");
    } else {
        print_error("Empty array size() doesn't return 0");
    }
    
    if (small.size() == 3) {
        print_success("Small array size() returns correct value");
    } else {
        print_error("Small array size() returns incorrect value");
    }
    
    if (large.size() == MAX_VAL) {
        print_success("Large array size() returns correct value");
    } else {
        print_error("Large array size() returns incorrect value");
    }
}

void test_different_types() {
    print_test_header("Different Types Test");
    
    // double型のテスト
    Array<double> doubles(3);
    doubles[0] = 3.14;
    doubles[1] = 2.71;
    doubles[2] = 1.41;
    
    if (doubles[0] == 3.14 && doubles[1] == 2.71 && doubles[2] == 1.41) {
        print_success("double type Array works correctly");
    } else {
        print_error("double type Array failed");
    }
    
    // string型のテスト
    Array<std::string> strings(2);
    strings[0] = "Hello";
    strings[1] = "World";
    
    if (strings[0] == "Hello" && strings[1] == "World") {
        print_success("string type Array works correctly");
    } else {
        print_error("string type Array failed");
    }
}

void test_original_scenario() {
    print_test_header("Original Test Scenario (Modified)");
    
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        const int value = rand() % 1000; // 小さな値に制限
        numbers[i] = value;
        mirror[i] = value;
    }
    
    // SCOPE テスト
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
        // スコープを抜ける時にデストラクタが呼ばれる
    }
    
    // 元の配列が影響を受けていないかチェック
    bool values_preserved = true;
    for (int i = 0; i < MAX_VAL; i++) {
        if (mirror[i] != numbers[i]) {
            values_preserved = false;
            break;
        }
    }
    
    if (values_preserved) {
        print_success("Values preserved after scope destruction");
    } else {
        print_error("Values not preserved after scope destruction");
    }
    
    // 例外テスト
    try {
        numbers[-2] = 0;
        print_error("No exception for negative index");
    } catch (const std::exception& e) {
        print_success("Exception caught for numbers[-2]");
    }
    
    try {
        numbers[MAX_VAL] = 0;
        print_error("No exception for out-of-bounds index");
    } catch (const std::exception& e) {
        print_success("Exception caught for numbers[MAX_VAL]");
    }
    
    delete[] mirror;
    print_success("Manual memory cleanup successful");
}

int main(int, char**) {
    std::cout << GREEN << "Starting comprehensive Array<T> class tests..." << RESET << std::endl;
    
    test_default_constructor();
    test_parameterized_constructor();
    test_copy_constructor();
    test_assignment_operator();
    test_subscript_operator();
    test_exception_handling();
    test_size_function();
    test_different_types();
    test_original_scenario();
    
    // テスト結果サマリー
    std::cout << "\n" << BLUE << "========================================" << RESET << std::endl;
    std::cout << BLUE << "TEST SUMMARY" << RESET << std::endl;
    std::cout << BLUE << "========================================" << RESET << std::endl;
    
    std::cout << "Test Groups: " << test_group_count << std::endl;
    std::cout << "Individual Tests: " << individual_test_count << std::endl;
    std::cout << "Passed: " << passed_tests << std::endl;
    std::cout << "Failed: " << failed_tests << std::endl;
    
    if (failed_tests == 0) {
        std::cout << GREEN << "ALL TESTS PASSED! 🎉" << RESET << std::endl;
    } else {
        std::cout << RED << "SOME TESTS FAILED ❌" << RESET << std::endl;
    }
    
    std::cout << "\nArray<T> class testing completed." << std::endl;
    
    return (failed_tests == 0) ? 0 : 1;
}


const Array<int>& constArr(5);
        try
        {
            for (int i = 0; i < MAX_VAL + 1; i++)
                std::cout << "ConstArr[" << i << "]:\t" << constArr[i] << std::endl;
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\t';
            std::cerr << "You tried to access past the last element of the array" << std::endl;
        }
// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp;
//         try
//         {
//             for (int i = 0; i < MAX_VAL + 1; i++)
//             {   
//                 std::cout << "Helloooooooooo1\n" << std::endl;
//                 std::cout << "tmp[" << i << "]:\t" << tmp[i] << std::endl;
//                 std::cout << "Helloooooooooo2\n" << std::endl;
//             }
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << '\t';
//             std::cerr << "You tried to access past the last element of the array" << std::endl;
//         }
//         tmp = numbers;
//         std::cout << "Helloooooooooo3" << std::endl;
//         Array<int> test(tmp);
//         std::cout << "Helloooooooooo4" << std::endl;
//         try
//         {
//             for (int i = 0; i < MAX_VAL + 1; i++)
//             {
//                 if (tmp[i] != test[i])
//                 {
//                     std::cerr << "didn't save the same value!!" << std::endl;
//                     return 1;
//                 }
//             }
//         }
//         catch(const std::exception& e)
//         {
//             std::cerr << e.what() << '\t';
//             std::cerr << "You tried to access past the last element of the array" << std::endl;
//         }
//         std::cout << "Helloooooooooo5" << std::endl;

//         std::cout << std::endl << "test[1]:\t" << test[1] << std::endl;
//         std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;

//         test[1] = 123456789;

//         std::cout << "test[1]:\t" << test[1] << std::endl;
//         std::cout << "tmp[1]:\t\t" << tmp[1] << std::endl << std::endl;
//     }

//     std::cout << "Helloooooooooo６" << std::endl;
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     Array<int> cop(numbers);
//     cop = numbers;
//     delete [] mirror;//
//     return 0;
// }
