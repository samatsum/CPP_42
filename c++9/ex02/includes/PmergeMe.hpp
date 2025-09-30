#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
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
    std::vector<int> _container;
    clock_t _start_time;
    clock_t _end_time;
    size_t _comparison_count;

    // Jacobsthal数を生成する（挿入順序の決定に使用）
    static std::vector<int> generateJacobsthalSequence(int n);
    void fordJohnsonSort(std::vector<int>& vec);
    size_t binarySearchInsertionPoint(const std::vector<int>& vec, int value, size_t end_pos);


public:
    PmergeMe();
    PmergeMe(char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);

    void sortVector();
    void printTime() const;
    void printContainerVector() const;
    void printComparisonCount() const;

private:
    void parseArguments(char **av);
    bool validateInput(const std::string& str);
};

#endif