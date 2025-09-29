#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include <iomanip>
#include <cctype>

/* ************************************************************************** */
PmergeMe::PmergeMe() : _start_time(0), _end_time(0)
{}

PmergeMe::PmergeMe(char **av) : _start_time(0), _end_time(0)
{
    parseArguments(av);
}

PmergeMe::PmergeMe(const PmergeMe& src) 
:_containerVector(src._containerVector),
 _start_time(src._start_time), 
 _end_time(src._end_time)
{}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    if (this != &rhs)
    {
        _containerVector = rhs._containerVector;
        _start_time = rhs._start_time;
        _end_time = rhs._end_time;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{}

/* ************************************************************************** */
// 引数をパースしてコンテナに格納
// なぜこの実装か：複数の引数を一つの文字列として扱い、整数として解析する
void PmergeMe::parseArguments(char **av)
{
    std::string args_string;
    
    // すべての引数を一つの文字列に連結
    for (int i = 1; av[i]; i++)
    {
        args_string += av[i];
        if (av[i + 1])
            args_string += " ";
    }
    
    // 入力検証
    if (!validateInput(args_string))
        throw std::invalid_argument("Error");
    
    // 文字列ストリームを使用して整数を抽出
    std::istringstream ss(args_string);
    int value;
    
    while (ss >> value)
    {
        // 負の数のチェック
        if (value < 0)
            throw std::invalid_argument("Error");
        // 重複チェック
        if (std::find(_containerVector.begin(), _containerVector.end(), value) != _containerVector.end())
            throw std::invalid_argument("Error");
        _containerVector.push_back(value);
    }
    if (_containerVector.empty())
        throw std::invalid_argument("Error");
}

/* ************************************************************************** */
// 入力文字列の検証
// 不正な文字や形式を事前に検出し、エラーを防ぐ
bool PmergeMe::validateInput(const std::string& str)
{
    if (str.empty())
        return false;
    for (size_t i = 0; i < str.length(); i++)
    {
        if (!std::isdigit(str[i]) && str[i] != ' ' && str[i] != '+')//ここ「＋」必要？
            return false;
        // 連続するスペースをチェック
        if (str[i] == ' ' && i + 1 < str.length() && str[i + 1] == ' ')
            return false;
    }
    return true;
}

/* ************************************************************************** */
// Jacobsthal数の計算
// J(n) = (2^(n+1) + (-1)^n) / 3
int PmergeMe::jacobsthal(int n) const
{
    double result = (std::pow(2.0, n + 1) + std::pow(-1.0, n)) / 3.0;
    //static_cast<int>(340.9999) == 340
    //static_cast<int>は四捨五入しない。ただ小数点以下を切り捨てする。
    //ー＞つまり、浮動小数点の計算時の誤差が有るかもしれないので、　「+0.5」した後にstatic_cast<int>がGood。
    return static_cast<int>(result + 0.5);
}

/* ************************************************************************** */
/* VECTOR ************************************************************ VECTOR */
/* ************************************************************************** */
// メインのソート関数
void PmergeMe::sortVector() {
    _start_time = std::clock();  // 計測開始
    fordJohnsonSortVector(_containerVector, 1);
    _end_time = std::clock();    // 計測終了
}

/* ************************************************************************** */
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
    
    bool has_odd = false;
    // 奇数個のユニットがあるかチェック
    if (unit_size % 2 == 1)
        has_odd = true;
    
    std::vector<int>::iterator start = vec.begin();
    std::vector<int>::iterator end = vec.begin() + (order * unit_size - (has_odd ? order : 0));//余った要素は後で挿入フェーズで処理
    
    /* 
    ** ペアワイズ比較フェーズ
    ** なぜこの処理か：隣接するグループ同士を比較し、
    ** 各グループの最後の要素（代表値）で大小を判定してスワップ
    ** 
    ** 例：order=1の場合
    ** [25, 21] → 比較して [21, 25] に並べ替え
    ** 
    ** 例：order=2の場合  
    ** [21, 25], [22, 23] → 25 > 23 なので [22, 23], [21, 25] に並べ替え
    */
    for (std::vector<int>::iterator it = start; it < end; it += (order * 2))
    {
        // 各グループの最後の要素を比較
        if (*(it + (order - 1)) > *(it + ((order * 2) - 1)))
        {
            // グループ全体をスワップ
            for (int i = 0; i < order; i++)
                std::swap(*(it + i), *(it + i + order));
        }
    }
    // printContainerVector();
    // std::cout << std::endl;
    
    // 再帰呼び出し：より大きなグループで処理を続ける
    std::cout << order << "order Swap END:" ;
    printContainerVector();
    std::cout << std::endl;
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
    std::vector<int> leftover;     // 余り要素
    int odd_element = 0;
    
    /*
    ** ここまでの状況を整理：
    ** 1. ペアワイズ比較が完了し、各ペアは「小さい方、大きい方」の順に並んでいる
    ** 2. 再帰呼び出しから戻ってきた（order *= 2して再帰し、order /= 2で戻った）
    ** 3. 今から、ソート済みの「大きい要素」と未ソートの「小さい要素」を分離する
    */
    
    /*
    ** 現在の配列の構造を図解（order=2の例）：
    ** 
    ** 配列: [22, 23, 24, 25, 18, 19, 20, 21, ...]
    **       |----ペア1----| |----ペア2----| 
    **       |グループA|グループB| |グループC|グループD|
    **         小    大      小    大
    ** 
    ** 各ペアは比較済み：グループA < グループB、グループC < グループD
    ** ただし、ペア間の大小関係は不明：グループBとグループDの関係は未確定
    */
    
    /*
    ** なぜ最初の2要素を特別扱いするのか？
    ** 
    ** Ford-Johnsonの理論的根拠：
    ** - 最初のペア（a1, b1）のa1は、他のどの要素とも比較されていない
    ** - a1は必ずメインチェーンの先頭になる（最小の可能性がある）
    ** - b1も確実にメインチェーンに含まれる（a1より大きいことが保証されている）
    ** 
    ** これにより、メインチェーンの初期状態として[a1, b1]が確定する
    */
    main_chain.push_back(*(start + order - 1));
    main_chain.push_back(*(start + order * 2 - 1));
    
    // 残りの要素をメインチェーンとペンドチェーンに分配
    for (std::vector<int>::iterator it = start + order * 2; it < end; it += order)
    {
        pend_chain.push_back(*(it + order - 1));
        it += order;
        if (it < end) {
            main_chain.push_back(*(it + order - 1));
        }
    }
    
    // 奇数個の場合の処理
    if (has_odd)
        odd_element = *(end + order - 1);
    
    // 余り要素の保存
    leftover.insert(leftover.end(), end + (order * (has_odd ? 1 : 0)), vec.end());
    
    // 挿入フェーズの実行
    if (has_odd || !pend_chain.empty()) {
        insertionPhaseVector(main_chain, pend_chain, odd_element, leftover, vec, has_odd, order);
    }
    else
    {
        std::cout << order <<"order insertionPhaseVector END:";
        printContainerVector();
        std::cout << std::endl;
    }
}

/* ************************************************************************** */
// 挿入フェーズの実装
// なぜこの実装か：Jacobsthal数列を使用して最適な挿入順序を決定し、
// 二分探索で効率的に要素を挿入する
void PmergeMe::insertionPhaseVector(std::vector<int>& main_chain, 
                              std::vector<int>& pend_chain,
                              int odd_element,
                              std::vector<int>& leftover,
                              std::vector<int>& vec,
                              bool has_odd,
                              int order)
{
    std::vector<int> original_vec = vec;  // 元の配列を保存
    std::vector<int>::iterator insert_pos;
    
    // ペンドチェーンが1要素の場合の単純な処理
    if (pend_chain.size() == 1)
    {
        // 二分探索で挿入位置を見つける
        insert_pos = std::upper_bound(main_chain.begin(), main_chain.end(), pend_chain[0]);
        main_chain.insert(insert_pos, pend_chain[0]);
    } 
    // ペンドチェーンが複数要素の場合：Jacobsthal数列を使用
    else if (pend_chain.size() > 1)
    {
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
        
        while (!pend_chain.empty())
        {
            // 次に処理する要素数を決定
            idx = jacobsthal(jc) - jacobsthal(jc - 1);
            if (idx > pend_chain.size())
                idx = pend_chain.size();
            
            decrease = 0;
            // 逆順で挿入（b3, b2の順序を実現）
            while (idx > 0)
            {
                // 探索範囲の決定
                insert_pos = main_chain.begin();
                if (jacobsthal(jc + count) - decrease <= main_chain.size())
                    insert_pos = main_chain.begin() + jacobsthal(jc + count) - decrease;
                else
                    insert_pos = main_chain.end();
                
                // 二分探索で適切な位置を見つけて挿入
                insert_pos = std::upper_bound(main_chain.begin(), insert_pos, pend_chain[idx - 1]);
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
    if (has_odd)
    {
        insert_pos = std::upper_bound(main_chain.begin(), main_chain.end(), odd_element);
        main_chain.insert(insert_pos, odd_element);
    }
    
// // 処理前の状態
// original_vec = [22, 23, 24, 25]  // 元の配列（グループ化された状態）
// main_chain = [23, 25]             // 代表値のみ（各グループの最後の要素）

// // 処理の流れ
// 1. main_chainから23を取得
// 2. original_vecで23を探す → 位置1で発見
// 3. グループ全体を取得：
//    - group_start = 位置1 - (2-1) = 位置0  // 22の位置
//    - group_end = 位置1 + 1 = 位置2        // 24の位置（範囲の終端）
//    - つまり[22, 23]を取得
// 4. resultに[22, 23]を追加

// 5. main_chainから25を取得
// 6. original_vecで25を探す → 位置3で発見
// 7. グループ全体を取得：
//    - group_start = 位置3 - (2-1) = 位置2  // 24の位置
//    - group_end = 位置3 + 1 = 位置4        // 範囲の終端
//    - つまり[24, 25]を取得
// 8. resultに[24, 25]を追加

// // 最終結果
// result = [22, 23, 24, 25]
    std::vector<int> result;
    for (std::vector<int>::iterator it = main_chain.begin(); it != main_chain.end(); ++it) {
        // original_vecから該当する値を探す（元の位置が保持されている）
        std::vector<int>::iterator found = std::find(original_vec.begin(), original_vec.end(), *it);
        if (found != original_vec.end()) {
            std::vector<int>::iterator group_start = found - (order - 1);
            std::vector<int>::iterator group_end = found + 1;
            result.insert(result.end(), group_start, group_end);
        }
    }
    
    // 余り要素を末尾に追加
    result.insert(result.end(), leftover.begin(), leftover.end());
    
    // 結果を元の配列に反映
    vec = result;
    std::cout << order <<"order insertionPhaseVector END:";
    printContainerVector();
    std::cout << std::endl;
}

/* ************************************************************************** */
// コンテナの内容を表示
void PmergeMe::printContainerVector() const
{
    for (std::vector<int>::const_iterator it = _containerVector.begin(); it != _containerVector.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

/* ************************************************************************** */
// 処理時間を表示
void PmergeMe::printTime() const
{
    double elapsed = static_cast<double>(_end_time - _start_time) / CLOCKS_PER_SEC;
    std::cout << "Time to process a range of " << _containerVector.size() 
              << " elements with std::vector : " 
              << std::fixed << std::setprecision(6) 
              << elapsed << " s" << std::endl;
}
