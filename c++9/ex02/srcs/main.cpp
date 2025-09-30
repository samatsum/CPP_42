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
        sorter.printContainer_Vector();
        std::cout << std::endl;
        
        sorter.sort_Vector();
        
        // ソート後の配列を表示
        std::cout << "After: ";
        sorter.printContainer_Vector();
        std::cout << std::endl;
        
        sorter.printTime();
        //S(21) = 理論的下限 = 66回(比較ソートの場合どんな比較ソートでも、「21個の数字をソートする際に、最低でも66回は比較が必要」ということ。)
        //21個の要素には 21! 通りの並び順が存在
        // 各比較は「yes/no」の2通りの結果を持つ
        // すべての並び順を区別するには少なくとも log₂(21!) 回の質問（比較）が必要
        // ⌈log₂ 21!⌉ = ⌈65.91...⌉ = 66回
        sorter.printComparisonCount(); 
    }
    catch (const std::exception& e)
    {
        std::cerr << "Error" << std::endl;
        return (1);
    }
    
    return (0);
}