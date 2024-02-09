#include "RPN.hpp"
#include <cctype>

bool is_op(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

void parse_arg(std::string &expr)
{
    int i = 0;
    while(expr[i])
    {
        if(expr[i] == ' ' || expr[i] == '\t')
           i++;
        else if(isdigit(expr[i]) || is_op(expr[i]))
        {
            if (expr[i + 1] != ' ' && expr[i + 1] != '\t' && expr[i + 1] != '\0'){
                throw std::exception();
            }
            i++;
        }
        else {
            throw std::exception();
        }
    }
}

int RPN(std::string &expr)
{
    parse_arg(expr);
    std::stack<int> stack;
    
    for (size_t i = 0; i < expr.length(); ++i) 
    {
        if (isdigit(expr[i])) 
            stack.push(expr[i] - '0');
        else if (is_op(expr[i])) 
        {
            if (stack.size() < 2) 
                throw std::exception();
            int a = stack.top();
            stack.pop();
            int b = stack.top();
            stack.pop();
            if (expr[i] == '+')
                stack.push(b + a);
            else if (expr[i] == '-')
                stack.push(b - a);
            else if (expr[i] == '*')
                stack.push(b * a);
            else if (expr[i] == '/')
                stack.push(b / a);
        }
    }
    if(stack.size() != 1)
        throw std::exception();
    return(stack.top());
}