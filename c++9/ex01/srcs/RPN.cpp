#include "../includes/RPN.hpp"

/* ************************************************************************** */
RPN::RPN(){}

RPN::~RPN(){}

RPN::RPN(const RPN& src)
{
    this->stack = src.stack;
}

RPN& RPN::operator=(const RPN& rhs)
{
    this->stack = rhs.stack;
    return (*this);
}

/* ************************************************************************** */
int RPN::isDigit(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (-1);
}

/* ************************************************************************** */
int RPN::isOperator(char c)
{
    if (c == '+' || c == '-' || c == '/' || c == '*')
        return (1);
    return (-1); 
}

/* ************************************************************************** */
int RPN::calcOperation(int a, int b, char op)
{
    if (op == '+')
        return (b+a);
    else if (op == '-')
        return (b-a);
    else if (op == '/')
    {
        if (a == 0)
        {
            std::cout << "Error : Zero '/'" << std::endl;
            exit(EXIT_FAILURE);
        }
        return (b/a);
    }
    else
        return (b*a);
}

/* ************************************************************************** */
void RPN::argvToString(char **argv)
{
    std::string expression(argv[1]);
    expEval(expression);
}

/* ************************************************************************** */
void RPN::expEval(std::string exp)
{
    size_t i = 0;
    size_t exp_len;
    int res;

    exp_len =  exp.length();
    while (i < exp_len)
    {
        while (isspace(exp[i]))
            i++;
        if (isDigit(exp[i]) != -1)
        {
            char tmp[2] = {exp[i], '\0'};
            this->stack.push(atoi(tmp));// "1'\0'2'\0'*'\0'..."みたいな感じで文字配列。
        }
        else if (isOperator(exp[i]) != -1)
        {
            if (this->stack.size() < 2)// 演算に必要な2つの数字があるかチェック
            {
                std::cout << "Error : 2 Digit is not now" << std::endl;
                exit(EXIT_FAILURE);
            }
            int a = this->stack.top();// 最初の数字を取得
            this->stack.pop();
            int b = this->stack.top();// 二番目の数字を取得
            this->stack.pop();
            res = calcOperation(a, b, exp[i]);
            this->stack.push(res);// 結果をスタックに戻す
        }
        else
        {
            std::cout << "Error : Non Operator(+-*/)" << std::endl;
            exit(EXIT_FAILURE);
        }
        i++;
    }
    if (this->stack.size() != 1)//ほんとは数字１つだけなのに…
    {
        std::cout << "Error : why {stack size != 1} ???" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::cout << this->stack.top() << std::endl;
}
