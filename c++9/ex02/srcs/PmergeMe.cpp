
#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <cctype>

/* ************************************************************************** */
// Orthodox Canonical Form  Argument Parsing
/* ************************************************************************** */
PmergeMe::PmergeMe() : _start_time(0), _end_time(0)
{}

PmergeMe::PmergeMe(char **av) : _start_time(0), _end_time(0)
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
    }
    return (*this);
}

PmergeMe::~PmergeMe()
{}

/* ************************************************************************** */
// Argument Parsing
/* ************************************************************************** */
void PmergeMe::parseArguments(char **av)
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

    std::istringstream ss(args_string);
    int value;
    while (ss >> value)
    {
        if (value < 0)
            throw std::invalid_argument("Error");
        _container.push_back(value);
    }
    if (_container.empty())
        throw std::invalid_argument("Error");

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
        return false;
    return (true);
}

/* ************************************************************************** */
// Jacobsthal数生成
/* ************************************************************************** */
std::vector<int> PmergeMe::generateJacobsthalSequence(int n)
{
    std::vector<int> jacob;
    jacob.push_back(0);
    if (n > 0)
        jacob.push_back(1);
    
    while (true)
    {
        size_t size = jacob.size();
        int next = jacob[size - 1] + 2 * jacob[size - 2];
        if (next >= n)
            break;
        jacob.push_back(next);
    }
    return (jacob);
}

/* ************************************************************************** */
// Ford-Johnson Algorithm
/* ************************************************************************** */

void PmergeMe::fordJohnsonSort(std::vector<int>& vec)
{
    // ベースケース
    if (vec.size() < 2)
        return;

    // === ステップ1: ペアリングとペア内ソート ===
    int leftover = -1;
    bool has_leftover = (vec.size() % 2 != 0);
    if (has_leftover)
    {
        leftover = vec.back();
        vec.pop_back();
    }

    std::vector<IntPair> pairs;
    for (size_t i = 0; i < vec.size(); i += 2)
    {
        IntPair p;
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
    // まず、大きい方の要素（a要素）を抽出
    std::vector<int> larger_elements;
    for (size_t i = 0; i < pairs.size(); ++i)
        larger_elements.push_back(pairs[i].first);

    // **重要**: 再帰的にFord-Johnsonソートを呼び出す
    fordJohnsonSort(larger_elements);

    // ソート結果を元のペアに反映
    // larger_elementsの順序に従ってpairsを並べ替える
    std::vector<IntPair> sorted_pairs;
    for (size_t i = 0; i < larger_elements.size(); ++i)
    {
        // larger_elements[i]に対応する元のペアを見つける
        for (size_t j = 0; j < pairs.size(); ++j)
        {
            if (pairs[j].first == larger_elements[i])
            {
                sorted_pairs.push_back(pairs[j]);
                // 同じ要素を二度使わないようにマークする（-1で無効化）
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
    
    if (has_leftover)
        pending_elements.push_back(leftover);

    // === ステップ4: 最適な順番での挿入 ===
    // 最初の保留要素(b1)をメインチェーンの先頭に挿入
    if (!pending_elements.empty())
        main_chain.insert(main_chain.begin(), pending_elements[0]);

    // a要素の位置を追跡する配列
    std::vector<size_t> a_positions;
    for (size_t i = 0; i < pairs.size(); ++i)
        a_positions.push_back(i + 1); // b1が先頭に入ったので+1

    // Jacobsthal数列に基づく挿入順序を生成
    std::vector<int> jacob_seq = generateJacobsthalSequence(pending_elements.size());
    std::vector<size_t> insertion_order;
    
    for (size_t k = 1; k < jacob_seq.size(); ++k)
    {
        int start = (k == 1) ? 1 : jacob_seq[k - 1];
        int end = jacob_seq[k];
        if (end > static_cast<int>(pending_elements.size()))
            end = pending_elements.size();
        // 降順で追加
        for (int i = end; i > start; --i)
            insertion_order.push_back(i - 1); // 0-indexed
    }
    
    // 残りの要素を追加
    int last_jacob = jacob_seq.back();
    if (last_jacob < static_cast<int>(pending_elements.size()))
    {
        for (size_t i = last_jacob; i < pending_elements.size(); ++i)
            insertion_order.push_back(i);
    }

    // 各pending要素を挿入
    for (size_t idx = 0; idx < insertion_order.size(); ++idx)
    {
        size_t b_index = insertion_order[idx];
        
        // b_indexが0の場合はすでに挿入済み
        if (b_index == 0)
            continue;
        
        int value_to_insert = pending_elements[b_index];
        
        // 探索範囲の上限を特定（対応するa要素の位置まで）
        size_t upper_bound_pos = a_positions[b_index - 1];
        
        // 二分探索で挿入位置を見つける
        std::vector<int>::iterator search_end = main_chain.begin() + upper_bound_pos + 1;
        std::vector<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), search_end, value_to_insert);
        size_t insert_index = std::distance(main_chain.begin(), insert_pos);
        main_chain.insert(insert_pos, value_to_insert);
        
        // a要素の位置を更新
        for (size_t i = 0; i < a_positions.size(); ++i)
        {
            if (a_positions[i] >= insert_index)
                a_positions[i]++;
        }
    }

    vec = main_chain;
}

/* ************************************************************************** */
// Public Interface
/* ************************************************************************** */

void PmergeMe::sortVector()
{
    _start_time = std::clock();
    fordJohnsonSort(_container);
    _end_time = std::clock();
}

void PmergeMe::printContainerVector() const
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
