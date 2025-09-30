#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <stdexcept>
#include <algorithm> // for std::swap, std::lower_bound
#include <iterator>  // for std::distance

// ペアを扱うための構造体。 firstが大きい方, secondが小さい方
struct IntPair
{
    int first;
    int second;
};

// IntPairを比較するための比較関数オブジェクト
struct ComparePairFirst
{
    bool operator()(const IntPair& a, const IntPair& b) const
    {
        return a.first < b.first;
    }
};


class PmergeMe {
private:
    std::vector<int> _container;
    clock_t _start_time;
    clock_t _end_time;

    // --- 正確なアルゴリズムのためのプライベートヘルパー関数 ---

    // Jacobsthal数を生成する（挿入順序の決定に使用）
    static std::vector<int> _generateJacobsthalSequence(int n);

    // 二分探索で挿入位置を見つける
    // std::lower_boundを使用するため、このヘルパーは不要になりますが、
    // 分かりやすさのために残すことも可能です。今回はstd::lower_boundを直接使います。

    // Ford-Johnsonソートの本体（再帰関数）
    void _fordJohnsonSort(std::vector<int>& vec);


public:
    // --- 既存のインターフェース ---
    PmergeMe();
    PmergeMe(char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);

    void sortVector();
    void printTime() const;
    void printContainerVector() const;

private:
    // --- 既存のヘルパー関数 ---
    void _parseArguments(char **av);
    bool _validateInput(const std::string& str);
};

#endif // PMERGEME_HPP