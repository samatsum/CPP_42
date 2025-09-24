/*
** PmergeMe.hpp - Ford-Johnson Algorithm (Merge-Insertion sortVector) 
** std::vector<int>専用実装
** 
** このアルゴリズムは比較回数を最小化することに特化したソートアルゴリズムです。
** 理論的に最小に近い比較回数でソートを実現します。
*/

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <string>
#include <ctime>

class PmergeMe {
private:
    std::vector<int> _containerVector;  // ソート対象のコンテナ
    clock_t _start_time;          // 処理開始時間
    clock_t _end_time;            // 処理終了時間
    
public:
    // コンストラクタ・デストラクタ
    PmergeMe();
    PmergeMe(char **av);
    ~PmergeMe();
    PmergeMe(const PmergeMe& src);
    PmergeMe& operator=(const PmergeMe& rhs);
    
    // パブリックメソッド
    void sortVector();                    // ソートの実行
    void printTime() const;          // 処理時間の表示
    void printContainerVector() const;     // コンテナの内容表示
    size_t size() const;            // サイズ取得
    
private:
    // Ford-Johnson algorithmのコア機能
    void fordJohnsonSortVector(std::vector<int>& vec, int order);
    
    // Jacobsthal数列の計算（挿入順序の最適化に使用）
    int jacobsthal(int n) const;
    
    // 挿入フェーズの処理
    void insertionPhase(std::vector<int>& main_chain, 
                       std::vector<int>& pend_chain,
                       int odd_element,
                       std::vector<int>& leftover,
                       std::vector<int>& vec,
                       bool has_odd,
                       int order);
    
    // ユーティリティ関数
    void parseArguments(char **av);     // 引数のパース
    bool validateInput(const std::string& str); // 入力検証
};

#endif // PMERGEME_HPP