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
// 中間位置での挿入がvectorより効率的な場合があるっぽい？？？
//https://dexall.co.jp/articles/?p=1935#i-5 これわかりやす
/* ************************************************************************** */
#include "../includes/PmergeMe.hpp"
#include <iostream>
#include <exception>

//注意！　このフォードジョンソンソートアルゴリズムは、要素nの数が、「1<= n <= 12 || 20 <= n <= 21」でのみ最適らしいぞ！
int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
        //S(21) = 理論的下限 = 66回(比較ソートの場合どんな比較ソートでも、「21個の数字をソートする際に、最悪でも66回は比較が必要」ということ。)
        //21個の要素には 21! 通りの並び順が存在
        // 各比較は「yes/no」の2通りの結果を持つ
        // すべての並び順を完全に区別するには少なくとも log₂(21!) 回の質問（比較）が必要
        // ⌈log₂ 21!⌉ = ⌈65.91...⌉ = 66回
    try
    {
        PmergeMe Vsorter(argv);
        std::cout << "Vector Before: ";
        Vsorter.printContainer_Vector();
        std::cout << std::endl;
        Vsorter.sort_Vector();
        std::cout << "Vector After: ";
        Vsorter.printContainer_Vector();
        std::cout << std::endl;
        Vsorter.printTime_Vector();
        Vsorter.printComparisonCount_Vector();
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        PmergeMe Dsorter(argv);
        std::cout << "Deque Before: ";
        Dsorter.printContainer_Deque();
        std::cout << std::endl;
        Dsorter.sort_Deque();
        std::cout << "DequeAfter: ";
        Dsorter.printContainer_Deque();
        std::cout << std::endl;
        Dsorter.printTime_Deque();
        Dsorter.printComparisonCount_Deque(); 
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    
    return (0);
}