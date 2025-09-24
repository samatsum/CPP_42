/*
** PmergeMe.cpp - Ford-Johnson Algorithmの実装
** std::vector<int>専用
** C++98準拠
*/

#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <cctype>  // for std::isdigit

// デフォルトコンストラクタ
PmergeMe::PmergeMe() : _start_time(0), _end_time(0) {}

// デストラクタ
PmergeMe::~PmergeMe() {}

// コピーコンストラクタ
PmergeMe::PmergeMe(const PmergeMe& src) 
    : _containerVector(src._containerVector), _start_time(src._start_time), _end_time(src._end_time) {}

// 代入演算子
PmergeMe& PmergeMe::operator=(const PmergeMe& rhs) {
    if (this != &rhs) {
        _containerVector = rhs._containerVector;
        _start_time = rhs._start_time;
        _end_time = rhs._end_time;
    }
    return *this;
}

// 引数付きコンストラクタ
// なぜこの実装か：コマンドライン引数を整数のベクターに変換する
PmergeMe::PmergeMe(char **av) : _start_time(0), _end_time(0) {
    parseArguments(av);
}

// 引数をパースしてコンテナに格納
// なぜこの実装か：複数の引数を一つの文字列として扱い、整数として解析する
void PmergeMe::parseArguments(char **av) {
    std::string args_string;
    
    // すべての引数を一つの文字列に連結
    for (int i = 1; av[i]; i++) {
        args_string += av[i];
        if (av[i + 1])
            args_string += " ";
    }
    
    // 入力検証
    if (!validateInput(args_string)) {
        throw std::invalid_argument("Error");
    }
    
    // 文字列ストリームを使用して整数を抽出
    std::istringstream ss(args_string);
    int value;
    
    while (ss >> value) {
        // 負の数のチェック
        if (value < 0) {
            throw std::invalid_argument("Error");
        }
        
        // 重複チェック
        if (std::find(_containerVector.begin(), _containerVector.end(), value) != _containerVector.end()) {
            throw std::invalid_argument("Error");
        }
        
        _containerVector.push_back(value);
    }
    
    if (_containerVector.empty()) {
        throw std::invalid_argument("Error");
    }
}

// 入力文字列の検証
// なぜこの実装か：不正な文字や形式を事前に検出し、エラーを防ぐ
bool PmergeMe::validateInput(const std::string& str) {
    if (str.empty()) return false;
    
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+') {
            return false;
        }
        
        // 連続するスペースをチェック
        if (str[i] == ' ' && i + 1 < str.length() && str[i + 1] == ' ') {
            return false;
        }
    }
    
    return true;
}

// Jacobsthal数の計算
// なぜこの実装か：Ford-Johnson algorithmの挿入フェーズで、
// 最適な挿入順序を決定するために使用される数列
// J(n) = (2^(n+1) + (-1)^n) / 3
// C++98対応：std::roundが使えないため、+0.5して切り捨てる
int PmergeMe::jacobsthal(int n) const {
    double result = (std::pow(2.0, n + 1) + std::pow(-1.0, n)) / 3.0;
    // C++98での四捨五入実装
    if (result >= 0) {
        return static_cast<int>(result + 0.5);
    } else {
        return static_cast<int>(result - 0.5);
    }
}

// メインのソート関数
void PmergeMe::sortVector() {
    _start_time = std::clock();  // 計測開始
    fordJohnsonSortVector(_containerVector, 1);
    _end_time = std::clock();    // 計測終了
}

// Ford-Johnson algorithmの実装
// なぜこの実装か：再帰的にペアを作り、比較・マージすることで、
// 比較回数を最小化する階層的なソートを実現
// order = 1 → 個々の要素をペアとして扱う
// order = 2 → 2要素のグループをペアとして扱う  
// order = 4 → 4要素のグループをペアとして扱う
// order = 8 → 8要素のグループをペアとして扱う
void PmergeMe::fordJohnsonSortVector(std::vector<int>& vec, int order)
{
    // ベースケース：要素が2未満の場合は処理不要
    int unit_size = vec.size() / order;
    if (unit_size < 2)
        return;
    
    // 奇数個のユニットがあるかチェック
    bool has_odd = (unit_size % 2 == 1);
    
    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.begin() + (order * unit_size - (has_odd ? order : 0));//余った要素は後で挿入フェーズで処理
    
    /* 
    ** ペアワイズ比較フェーズ
    ** なぜこの処理か：隣接するグループ同士を比較し、
    ** 各グループの最後の要素（代表値）で大小を判定してスワップ
    ** 
    ** 例：order=1の場合
    ** [25], [24] → 比較して [24], [25] に並べ替え
    ** 
    ** 例：order=2の場合  
    ** [24, 25], [22, 23] → 25 > 23 なので [22, 23], [24, 25] に並べ替え
    */
    for (std::vector<int>::iterator it = start; it < end; it += (order * 2))
    {
        // 各グループの最後の要素を比較
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1)))
        {
            // グループ全体をスワップ
            for (int i = 0; i < order; i++)
            {
                std::swap(*(it + i), *(it + i + order));
            }
        }
    }
    
    // 再帰呼び出し：より大きなグループで処理を続ける
    order *= 2;
    fordJohnsonSortVector(vec, order);
    order /= 2;
    
    /*
    ** 挿入フェーズの準備
    ** なぜこの処理か：ソート済みのメインチェーンと、
    ** 挿入すべきペンドチェーンを生成する
    */
    std::vector<int> main_chain;   // メインチェーン（大きい要素）
    std::vector<int> pend_chain;   // ペンドチェーン（小さい要素）
    int odd_element = 0;
    std::vector<int> leftover;     // 余り要素
    
    // 最初の要素は無条件でメインチェーンに追加
    main_chain.push_back(*(start + order - 1));
    main_chain.push_back(*(start + order * 2 - 1));
    
    // 残りの要素をメインチェーンとペンドチェーンに分配
    for (std::vector<int>::iterator it = start + order * 2; it < end; it += order) {
        pend_chain.push_back(*(it + order - 1));
        it += order;
        if (it < end) {
            main_chain.push_back(*(it + order - 1));
        }
    }
    
    // 奇数個の場合の処理
    if (has_odd) {
        odd_element = *(end + order - 1);
    }
    
    // 余り要素の保存
    leftover.insert(leftover.end(), end + (order * (has_odd ? 1 : 0)), vec.end());
    
    // 挿入フェーズの実行
    if (has_odd || !pend_chain.empty()) {
        insertionPhase(main_chain, pend_chain, odd_element, leftover, vec, has_odd, order);
    }
}

// 挿入フェーズの実装
// なぜこの実装か：Jacobsthal数列を使用して最適な挿入順序を決定し、
// 二分探索で効率的に要素を挿入する
void PmergeMe::insertionPhase(std::vector<int>& main_chain, 
                              std::vector<int>& pend_chain,
                              int odd_element,
                              std::vector<int>& leftover,
                              std::vector<int>& vec,
                              bool has_odd,
                              int order)
{
    std::vector<int>::iterator insert_pos;
    
    // ペンドチェーンが1要素の場合の単純な処理
    if (pend_chain.size() == 1) {
        // 二分探索で挿入位置を見つける
        insert_pos = std::upper_bound(main_chain.begin(), main_chain.end(), 
                                     pend_chain[0]);
        main_chain.insert(insert_pos, pend_chain[0]);
    } 
    // ペンドチェーンが複数要素の場合：Jacobsthal数列を使用
    else if (pend_chain.size() > 1) {
        /*
        ** Jacobsthal数列による最適化された挿入
        ** なぜこの順序か：挿入時の比較回数を最小化するため、
        ** 特定の順序で要素を挿入する必要がある
        ** 
        ** 例：b3, b2, b5, b4, b11, b10, b9, b8, b7, b6 の順で挿入
        ** この順序は Jacobsthal数列 (1, 3, 5, 11, 21, ...) に基づく
        */
        size_t jc = 3;  // Jacobsthal数列のインデックス（3から開始）
        size_t count = 0;
        size_t idx;
        size_t decrease;
        
        while (!pend_chain.empty()) {
            // 次に処理する要素数を決定
            idx = jacobsthal(jc) - jacobsthal(jc - 1);
            if (idx > pend_chain.size()) {
                idx = pend_chain.size();
            }
            
            decrease = 0;
            // 逆順で挿入（b3, b2の順序を実現）
            while (idx > 0) {
                // 探索範囲の決定
                insert_pos = main_chain.begin();
                if (jacobsthal(jc + count) - decrease <= main_chain.size()) {
                    insert_pos = main_chain.begin() + jacobsthal(jc + count) - decrease;
                } else {
                    insert_pos = main_chain.end();
                }
                
                // 二分探索で適切な位置を見つけて挿入
                insert_pos = std::upper_bound(main_chain.begin(), insert_pos, 
                                             pend_chain[idx - 1]);
                main_chain.insert(insert_pos, pend_chain[idx - 1]);
                pend_chain.erase(pend_chain.begin() + idx - 1);
                
                idx--;
                decrease++;
                count++;
            }
            jc++;
        }
    }
    
    // 奇数要素の挿入
    if (has_odd) {
        insert_pos = std::upper_bound(main_chain.begin(), main_chain.end(), odd_element);
        main_chain.insert(insert_pos, odd_element);
    }
    
    /*
    ** 元の配列の再構築
    ** なぜこの処理か：メインチェーンの各要素に対応する
    ** 元のグループ全体を正しい順序で配置し直す必要がある
    */
   // これ、もともと元の配列をコピーしたものを作っておけば良いんじゃないの？
    std::vector<int> result;
    for (std::vector<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it) {
        // 元の配列から該当する値を探し、そのグループ全体をコピー
        std::vector<int>::iterator found = std::find(vec.begin(), vec.end(), *it);
        if (found != vec.end()) {
            // グループ全体（order個の要素）をコピー
            std::vector<int>::iterator group_start = found - (order - 1);
            std::vector<int>::iterator group_end = found + 1;
            result.insert(result.end(), group_start, group_end);
        }
    }
    
    // 余り要素を末尾に追加
    result.insert(result.end(), leftover.begin(), leftover.end());
    
    // 結果を元の配列に反映
    vec = result;
}

// コンテナの内容を表示
void PmergeMe::printContainerVector() const {
    for (std::vector<int>::const_iterator it = _containerVector.begin(); 
         it != _containerVector.end(); ++it) {
        std::cout << *it << " ";
    }
}

// 処理時間を表示
void PmergeMe::printTime() const {
    double elapsed = static_cast<double>(_end_time - _start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << _containerVector.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(6) 
              << elapsed << " s" << std::endl;
}

// サイズ取得
//これどこで使われてるの？
size_t PmergeMe::size() const {
    return (_containerVector.size());
}
