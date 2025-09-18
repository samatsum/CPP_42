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
int main(int ac , char **av){
    try{
        if(ac > 2){
            PmergeMe<std::deque<int > > Deque(av);
            PmergeMe<std::vector<int > > Vector(av);

            std::cout << "Before: " << Deque << std::endl;
            Deque.sort();
            Vector.sort();
            std::cout << "After: " << Deque << std::endl;
            
            Deque.sort_time();
            Vector.sort_time();

        }else 
            throw "bad trip";
    }catch(...){
        std::cerr << "bad trip " << std::endl;
    }
    return 0;
}