#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <cstdlib>
# include <cstring>
# include <stack>
# include <list>
# include <sstream>

class RPN
{
    private:
        std::stack<int, std::list<int> > stack;  // listを内部コンテナに指定
    public:
        RPN();
        ~RPN();
        RPN(const RPN& copy);
        RPN& operator=(const RPN& in);

        void argvToString(char **argv);
        void expEval(std::string exp);
        int isDigit(char c);
        int isOperator(char c);
        int calcOperation(int a, int b, char op);
};
#endif