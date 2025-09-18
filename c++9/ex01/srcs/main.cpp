#include "../includes/RPN.hpp"

//スタックの特性（LIFO: Last In, First Out）が逆ポーランド記法の計算にyosage
// →　std::stack(内部コンテナはlist(特にlist特有のなにかしらを使うわけではない))使います！ ex02では、stackとlistとmap以外を使う！
//./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
/* ************************************************************************** */
int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "ERROR: argc is not 2" << std::endl;
    else
    {
        RPN exp;
        exp.argvToString(argv);
    }
}

