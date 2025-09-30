#include "../includes/PmergeMe.hpp"

//vector と　dequeを使うぞ！
// stackの内部コンテナがデフォルトではdequeだって？
// ex01ではstd::stackはstd::listを内部コンテナに指定していて、std::dequeの特有機能は未使用！！！！だからex02でdeque使っていいやろ！
// std::vectorの特性：
// 連続したメモリ領域に要素を格納
// ランダムアクセスが非常に高速
// 末尾への挿入・削除は高速だが、中間位置での操作は遅い
// メモリ使用量が効率的
// std::dequeの特性：
// 複数のメモリブロックに分散して格納
// 両端での挿入・削除が高速
// ランダムアクセスは可能だが、vectorより若干遅い
// 中間位置での挿入がvectorより効率的な場合がある
/* ************************************************************************** */
#include "../includes/PmergeMe.hpp"
/*
** main.cpp - Ford-Johnson Algorithmのメイン関数
** std::vector専用版
**
** このプログラムの目的：
** 1. コマンドライン引数から整数列を受け取る
** 2. std::vectorでFord-Johnson algorithmを実行
** 3. ソート結果と処理時間を表示
*/

#include <iostream>
#include <exception>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }

    try
    {
        // PmergeMeオブジェクトの作成と初期化
        // 不正な入力があれば例外を投げる
        PmergeMe sorter(argv);
        
        // ソート前の配列を表示
        std::cout << "Before: ";
        sorter.printContainerVector();
        std::cout << std::endl;
        
        // Ford-Johnson algorithmでソート実行
        // sortVector()メソッド内で開始・終了時刻を記録
        sorter.sortVector();
        
        // ソート後の配列を表示
        std::cout << "After: ";
        sorter.printContainerVector();
        std::cout << std::endl;
        
        sorter.printTime();
        //S(21) = 理論的下限 = 66回(どんなアルゴリズムでも、「21個の数字をソートする際に、最低でも66回は比較が必要」ということ。)
        sorter.printComparisonCount();
        
    }
    catch (const std::exception& e)
    {
        /*
        ** エラー処理
        ** なぜこの例外処理か：
        ** - 不正な入力（負の数、文字列、重複など）を検出
        ** - メモリ不足などの予期しないエラーに対応
        ** - 課題要件では"Error"のみを表示
        */
        std::cerr << "Error" << std::endl;
        return (1);
    }
    
    return (0);
}