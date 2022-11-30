#include <stack>
#include <string>
#include <iostream>

bool are_brackets_balanced(std::string expr) {
    std::stack<char> stack;
    int i = 0;
    while (expr[i] != '\0')
    {
        if (expr[i] == '(' || expr[i] == '{' || expr[i] =='[')
        {
            stack.push(expr[i]);
            i++;
        }
        if (expr[i] == ')')
        {
            if (stack.top() != '(')
            {
                return false;
            }else
            {
                stack.pop();
            }
            i++;
        }
        if (expr[i] == '}')
        {
            if (stack.top() != '{')
            {
                return false;
            }else
            {
                stack.pop();
            }
            i++;
        }
        if (expr[i] == ']')
        {
            if (stack.top() != '[')
            {
                return false;
            }else
            {
                stack.pop();
            }
            i++;
        }
        
    }
    return true;
}

int main()
{
    std:: string s ="(((())))";
    std::cout << std::boolalpha << are_brackets_balanced(s);
}