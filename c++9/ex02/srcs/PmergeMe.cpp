#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <stdexcept>
#include <iomanip>
#include <cctype>

/* ************************************************************************** */
// Orthodox Canonical Form & Argument Parsing (変更なし)
/* ************************************************************************** */
PmergeMe::PmergeMe() : _start_time(0), _end_time(0) {}
PmergeMe::PmergeMe(char **av) : _start_time(0), _end_time(0)
{
    _parseArguments(av);
}
PmergeMe::~PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& src) { *this = src; }
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        _container = rhs._container;
        _start_time = rhs._start_time;
        _end_time = rhs._end_time;
    }
    return *this;
}
void PmergeMe::_parseArguments(char **av) {
    std::string args_string;
    for (int i = 1; av[i]; i++) {
        args_string += av[i];
        if (av[i + 1]) args_string += " ";
    }

    if (!_validateInput(args_string)) throw std::invalid_argument("Error");

    std::istringstream ss(args_string);
    int value;
    while (ss >> value) {
        if (value < 0) throw std::invalid_argument("Error");
        _container.push_back(value);
    }
    if (_container.empty()) throw std::invalid_argument("Error");

    std::vector<int> sorted_clone = _container;
    std::sort(sorted_clone.begin(), sorted_clone.end());
    for (size_t i = 0; i < sorted_clone.size() - 1; ++i) {
        if (sorted_clone[i] == sorted_clone[i+1]) throw std::invalid_argument("Error");
    }
}
bool PmergeMe::_validateInput(const std::string& str) {
    if (str.empty() || str.find_first_not_of("0123456789 ") != std::string::npos) return false;
    return true;
}


/* ************************************************************************** */
// Ford-Johnson Algorithm Implementation (Corrected)
/* ************************************************************************** */

// ペアの 'first' 要素を比較するためのヘルパー
bool comparePairs(const IntPair& a, const IntPair& b) {
    return a.first < b.first;
}

// ヤコブスタール数列を生成
std::vector<int> PmergeMe::_generateJacobsthalSequence(int n) {
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n) {
        jacob.push_back(jacob[jacob.size() - 1] + 2 * jacob[jacob.size() - 2]);
    }
    return jacob;
}

void PmergeMe::_fordJohnsonSort(std::vector<int>& vec) {
    if (vec.size() < 2) {
        return;
    }

    // === ステップ1: ペアリングとペア内ソート ===
    int leftover = -1;
    bool has_leftover = (vec.size() % 2 != 0);
    if (has_leftover) {
        leftover = vec.back();
        vec.pop_back();
    }

    std::vector<IntPair> pairs;
    for (size_t i = 0; i < vec.size(); i += 2) {
        IntPair p;
        if (vec[i] > vec[i+1]) {
            p.first = vec[i];
            p.second = vec[i+1];
        } else {
            p.first = vec[i+1];
            p.second = vec[i];
        }
        pairs.push_back(p);
    }

    // === ステップ2: 大きい方の要素('a'要素)のリストを再帰的にソート ===
    // このステップは、ペアのリストを'first'要素基準でソートすることで実現
    std::sort(pairs.begin(), pairs.end(), comparePairs);

    // === ステップ3: メインチェーンと保留要素のリストを作成 ===
    std::vector<int> main_chain;
    std::vector<int> pending_elements;
    main_chain.reserve(vec.size());
    pending_elements.reserve(pairs.size());

    for (size_t i = 0; i < pairs.size(); ++i) {
        main_chain.push_back(pairs[i].first);
        pending_elements.push_back(pairs[i].second);
    }

    // === ステップ4: 最適な順番での挿入 ===
    // 最初の保留要素(b1)をメインチェーンの先頭に挿入
    main_chain.insert(main_chain.begin(), pending_elements[0]);

    // ヤコブスタール数に基づいた挿入順序で挿入
    std::vector<int> jacob_seq = _generateJacobsthalSequence(pending_elements.size());
    size_t last_inserted = 1;

    for (size_t k = 2; k < jacob_seq.size(); ++k) {
        size_t end = jacob_seq[k];
        if (end > pending_elements.size()) {
            end = pending_elements.size();
        }

        for (size_t i = end; i > last_inserted; --i) {
            int value_to_insert = pending_elements[i - 1];
            
            // 探索範囲の上限を特定 (a_i)
            int upper_bound_val = pairs[i - 1].first;
            std::vector<int>::iterator end_pos = std::find(main_chain.begin(), main_chain.end(), upper_bound_val);

            // 二分探索で挿入位置を見つける
            std::vector<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), end_pos, value_to_insert);
            main_chain.insert(insert_pos, value_to_insert);
        }
        last_inserted = end;
    }
    
    // 最後に余り要素を挿入
    if (has_leftover) {
        std::vector<int>::iterator insert_pos = std::lower_bound(main_chain.begin(), main_chain.end(), leftover);
        main_chain.insert(insert_pos, leftover);
    }

    vec = main_chain;
}




/* ************************************************************************** */
// Public Interface
/* ************************************************************************** */

void PmergeMe::sortVector() {
    _start_time = std::clock();
    _fordJohnsonSort(_container);
    _end_time = std::clock();
}

void PmergeMe::printContainerVector() const {
    for (std::vector<int>::const_iterator it = _container.begin(); it != _container.end(); ++it) {
        std::cout << *it << " ";
    }
}

void PmergeMe::printTime() const {
    double elapsed = static_cast<double>(_end_time - _start_time) / CLOCKS_PER_SEC * 1000000.0;
    std::cout << "Time to process a range of " << _container.size()
              << " elements with std::vector : "
              << std::fixed << std::setprecision(5) << elapsed
              << " us" << std::endl;
}