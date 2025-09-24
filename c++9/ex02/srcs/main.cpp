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

int main(int argc, char **argv) {
    // 引数チェック
    // なぜこのチェックか：最低でも2つの引数（プログラム名 + 1つ以上の数値）が必要
    if (argc < 2) {
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    try {
        // PmergeMeオブジェクトの作成と初期化
        // なぜこの実装か：コンストラクタで引数をパースし、
        // 不正な入力があれば例外を投げる設計
        PmergeMe sorter(argv);
        
        // ソート前の配列を表示
        // なぜこの表示か：課題要件でBeforeとAfterの表示が必要
        std::cout << "Before: ";
        sorter.printContainerVector();
        std::cout << std::endl;
        
        // Ford-Johnson algorithmでソート実行
        // なぜここでソートか：時間計測も同時に行うため、
        // sortVector()メソッド内で開始・終了時刻を記録
        sorter.sortVector();
        
        // ソート後の配列を表示
        std::cout << "After: ";
        sorter.printContainerVector();
        std::cout << std::endl;
        
        // 処理時間の表示
        // なぜこの形式か：課題で指定された出力形式
        // "Time to process a range of N elements with std::vector : X.XXXXXX s"
        sorter.printTime();
        
    } catch (const std::exception& e) {
        /*
        ** エラー処理
        ** なぜこの例外処理か：
        ** - 不正な入力（負の数、文字列、重複など）を検出
        ** - メモリ不足などの予期しないエラーに対応
        ** - 課題要件では"Error"のみを表示
        */
        std::cerr << "Error" << std::endl;
        return 1;
    }
    
    return 0;
}