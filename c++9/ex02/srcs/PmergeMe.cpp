
#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <cctype>
#include <climits>

/* ************************************************************************** */
// Orthodox Canonical Form  Argument Parsing
/* ************************************************************************** */
PmergeMe::PmergeMe() : _start_time(0), _end_time(0), _comparison_count(0)
{}

PmergeMe::PmergeMe(char **av) : _start_time(0), _end_time(0), _comparison_count(0)
{
    parseArguments(av);
}

PmergeMe::PmergeMe(const PmergeMe& src)
{
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        _container = rhs._container;
        _start_time = rhs._start_time;
        _end_time = rhs._end_time;
        _comparison_count = rhs._comparison_count;
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{}

/* ************************************************************************** */
// Argument Parsing
/* ************************************************************************** */
void PmergeMe::parseArguments(char **av)// INTMAXのチェック足りないな。
{
    std::string args_string;
    for (int i = 1; av[i]; i++)
    {
        args_string += av[i];
        if (av[i + 1])
            args_string += " ";
    }

    if (!validateInput(args_string))
        throw std::invalid_argument("Error");

    //std::istringstreamは文字列を入力ストリーム(string stream)として扱うクラス
    std::istringstream string_stream(args_string);
    size_t value;
    // string_stream >> valueはストリームから空白（スペース、タブ、改行）を自動的にスキップして次の整数(int)を読み取る演算子
    while (string_stream >> value)
    {
        if (value < 0 || value > INT_MAX)
            throw std::invalid_argument("Error");
        _container.push_back(static_cast<int>(value));
    }
    // かぶってる数値探し
    std::vector<int> sorted_clone = _container;
    std::sort(sorted_clone.begin(), sorted_clone.end());
    for (size_t i = 0; i < sorted_clone.size() - 1; ++i)
    {
        if (sorted_clone[i] == sorted_clone[i+1])
            throw std::invalid_argument("Error");
    }
}

bool PmergeMe::validateInput(const std::string& str)
{
    if (str.empty() || str.find_first_not_of("0123456789 ") != std::string::npos)
        return (false);
    return (true);
}

/* ************************************************************************** */
// Binary Search
/* ************************************************************************** */
size_t PmergeMe::binarySearchInsertionPoint(const std::vector<int>& vec, int value, size_t end_pos)
{
    size_t left = 0;
    size_t right = end_pos;
    
    while (left < right)
    {
        size_t mid = left + (right - left) / 2;
        
        //要素の比較した回数をカウント
        _comparison_count++;
        if (vec[mid] < value)
            left = mid + 1;
        else
            right = mid;
    }
    
    return (left);
}

/* ************************************************************************** */
// Jacobsthal数生成
/* ************************************************************************** */
//ヤーコプスタール数とは、下記定義によって表す数である。
// J(0) = 0
// J(1) = 1
// J(n) = J(n-1) + 2×J(n-2)  (n ≥ 2)
// Jacobsthal数 : 0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, ...
//  [Art Of Computer Programming, Vol.3]には、J(n) = (2^(n+1) + (-1)^n) / 3　とある。
// →　これは、Jacobsthal数の項数２以降（1, 3, 5, 11...）の別の書き方に過ぎない。（https://en.wikipedia.org/wiki/Jacobsthal_number）
//　浮動小数点の計算とかいう危ない橋渡るより、こっちの方が確実だよね。（C++98だからstd::round()使えないし。）
std::vector<int> PmergeMe::generateJacobsthalSequence_Vector(int n)
{
    std::vector<int> jacob;
    if (n <= 1)
        return (jacob);
    
    int j_prev2 = 0;// J(k-2)
    int j_prev1 = 1; // J(k-1)
    int j_current = 1;// J(2) = J(1) + 2*J(0) = 1
    
    while (j_current < n)
    {
        jacob.push_back(j_current);
        int j_next = j_current + (2 * j_prev1);
        j_prev2 = j_prev1;
        j_prev1 = j_current;
        j_current = j_next;
    }
    
    return (jacob);
}

/* ************************************************************************** */
// Ford-Johnson Algorithm
/* ************************************************************************** */
void PmergeMe::fordJohnsonSort_Vector(std::vector<int>& vec)
{
    if (vec.size() < 2)
        return;

    // === ステップ1: ペアリングとペア内ソート ===
    int odd_element = -1;
    bool has_odd_element = (vec.size() % 2 != 0);
    if (has_odd_element)
    {
        odd_element = vec.back();
        vec.pop_back();
    }

    std::vector<IntPair> pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        IntPair p;
        
        //要素の比較した回数をカウント
        _comparison_count++;
        if (vec[i] > vec[i+1])
        {
            p.first = vec[i];
            p.second = vec[i+1];
        }
        else
        {
            p.first = vec[i+1];
            p.second = vec[i];
        }
        pairs.push_back(p);
    }

    // === ステップ2: 大きい方の要素を再帰的にソート ===
    std::vector<int> larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger_elements.push_back(pairs[i].first);

    // 再帰的にFord-Johnsonソートを呼び出す
    fordJohnsonSort_Vector(larger_elements);

    // ソート結果を元のペアに反映
    std::vector<IntPair> sorted_pairs;
    for (size_t i = 0; i < larger_elements.size(); ++i)
    {
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == larger_elements[i])
            {
                sorted_pairs.push_back(pairs[j]);
                pairs[j].first = -1;
                break;
            }
        }
    }
    pairs = sorted_pairs;

    // === ステップ3: メインチェーンと保留要素のリストを作成 ===
    std::vector<int> main_chain;
    std::vector<int> pending_elements;
    main_chain.reserve(vec.size() + 1);
    pending_elements.reserve(pairs.size() + 1);

    for (size_t i = 0; i < pairs.size(); ++i)
    {
        main_chain.push_back(pairs[i].first);
        pending_elements.push_back(pairs[i].second);
    }
    
    if (has_odd_element)
        pending_elements.push_back(odd_element);

    // === ステップ4: 最適な順番での挿入 ===
    if (!pending_elements.empty())
        main_chain.insert(main_chain.begin(), pending_elements[0]);// 比較回数をカウントしないでOK。

    // a要素の位置を追跡
    std::vector<size_t> a_positions;
    for (size_t i = 0; i < pairs.size(); ++i)
        a_positions.push_back(i + 1);

    // Jacobsthal数列に基づく挿入順序を生成
    std::vector<int> jacob_seq = generateJacobsthalSequence_Vector(pending_elements.size());
    // for (std::vector<int>::const_iterator it = jacob_seq.begin(); it !=  jacob_seq.end(); ++it)
    //     std::cout << *it << " ";
    // std::cout << std::endl;

    std::vector<size_t> insertion_order;

    for (size_t k = 1; k < jacob_seq.size(); ++k)
    {
        int start = jacob_seq[k - 1];
        int end = jacob_seq[k];
        
        //endを制限する
        if (end > static_cast<int>(pending_elements.size()))
            end = pending_elements.size();
        
        for (int i = end; i > start; --i)
            insertion_order.push_back(i - 1);
    }

    //jacob_seqが空でないかチェック
    if (!jacob_seq.empty())
    {
        int last_jacob = jacob_seq.back();
        if (last_jacob < static_cast<int>(pending_elements.size()))
        {
            for (size_t i = last_jacob; i < pending_elements.size(); ++i)
                insertion_order.push_back(i);
        }
    }

    // 各pending要素を挿入
    for (size_t idx = 0; idx < insertion_order.size(); ++idx)
    {
        size_t b_index = insertion_order[idx];
        
        if (b_index == 0)
            continue;
        
        int value_to_insert = pending_elements[b_index];
        size_t upper_bound_pos = a_positions[b_index - 1];
        // 2分探索
        size_t insert_index = binarySearchInsertionPoint(main_chain, value_to_insert, upper_bound_pos + 1);
        
        main_chain.insert(main_chain.begin() + insert_index, value_to_insert);
        
        // a要素の位置を更新
        for (size_t i = 0; i < a_positions.size(); ++i)
        {
            if (a_positions[i] >= insert_index)
                a_positions[i]++;
        }
    }
    //　pendとoddを挿入しきったmainを元の配列に代入。
    vec = main_chain;
}


/* ************************************************************************** */
// Public Interface
/* ************************************************************************** */

void PmergeMe::sort_Vector()
{
    _comparison_count = 0;
    _start_time = std::clock();
    fordJohnsonSort_Vector(_container);
    _end_time = std::clock();
}

void PmergeMe::printContainer_Vector() const
{
    for (std::vector<int>::const_iterator it = _container.begin(); it != _container.end(); ++it)
        std::cout << *it << " ";
}

void PmergeMe::printTime() const
{
    double elapsed = static_cast<double>(_end_time - _start_time) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << _container.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << elapsed
              << " us" << std::endl;
}

void PmergeMe::printComparisonCount() const
{
    std::cout << "Number of comparisons: " << _comparison_count << std::endl;
}