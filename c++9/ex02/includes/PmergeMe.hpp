#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include <ctime>
#include <stdexcept>
#include <algorithm>
#include <iterator>

struct IntPair
{
    int first;
    int second;
};

class PmergeMe {
private:
    std::vector<int> _container_vector;
    std::deque<int> _container_deque;
    
    clock_t _start_time_vector;
    clock_t _end_time_vector;
    clock_t _start_time_deque;
    clock_t _end_time_deque;
    
    size_t _comparison_count_vector;
    size_t _comparison_count_deque;

    // Vector用
    static std::vector<int> generateJacobsthalSequence_Vector(int n);
    void fordJohnsonSort_Vector(std::vector<int>& vec);
    size_t binarySearchInsertionPoint_Vector(const std::vector<int>& vec, int value, size_t end_pos);

    // Deque用
    static std::deque<int> generateJacobsthalSequence_Deque(int n);
    void fordJohnsonSort_Deque(std::deque<int>& deq);
    size_t binarySearchInsertionPoint_Deque(const std::deque<int>& deq, int value, size_t end_pos);

public:
    PmergeMe();
    PmergeMe(char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);

    void sort_Vector();
    void sort_Deque();
    
    void printTime_Vector() const;
    void printTime_Deque() const;
    
    void printContainer_Vector() const;
    void printContainer_Deque() const;
    
    void printComparisonCount_Vector() const;
    void printComparisonCount_Deque() const;

private:
    void parseArguments(char **av);
    bool validateInput(const std::string& str);
};

#endif

// #ifndef PMERGEME_HPP
// #define PMERGEME_HPP

// #include <iostream>
// #include <vector>
// #include <string>
// #include <ctime>
// #include <stdexcept>
// #include <algorithm>
// #include <iterator>

// struct IntPair
// {
//     int first;
//     int second;
// };


// class PmergeMe {
// private:
//     std::vector<int> _container;
//     clock_t _start_time;
//     clock_t _end_time;
//     size_t _comparison_count;

//     // Jacobsthal数を生成する（挿入順序の決定に使用）
//     static std::vector<int> generateJacobsthalSequence_Vector(int n);
//     void fordJohnsonSort_Vector(std::vector<int>& vec);
//     size_t binarySearchInsertionPoint(const std::vector<int>& vec, int value, size_t end_pos);


// public:
//     PmergeMe();
//     PmergeMe(char **av);
//     ~PmergeMe();
//     PmergeMe(const PmergeMe& src);
//     PmergeMe& operator=(const PmergeMe& rhs);

//     void sort_Vector();
//     void printTime() const;
//     void printContainer_Vector() const;
//     void printComparisonCount() const;

// private:
//     void parseArguments(char **av);
//     bool validateInput(const std::string& str);
// };

// #endif