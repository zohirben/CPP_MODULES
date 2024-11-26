#include "RPN.hpp"

int main(int ac, char **av)
{
    std::stack<int> Stack;
    if (ac != 2)
    {
        std::cerr << "Error: bad format" << std::endl;
        return (1);
    }

    // we used stack because its the most straight forward way to calculate an RPN and especially optimal for this notation
    std::istringstream ss(av[1]);
    std::string token;

    int a;
    int b;
    int count = 0;
    while (ss >> token)
    {
        // in order to use std::atoi we needed to convert token to C style first
        if (isDigits(token))
        {
            Stack.push(atoi(token.c_str()));
            count++;
            if (count >= 10)
            {
                std::cerr << "Error" << std::endl;
                return (1);
            }
        }
        else if (token.find_first_of("+-*/") != std::string::npos && token.size() == 1)
        {
            b = Stack.top();
            Stack.pop();
            a = Stack.top();
            Stack.pop();
            if (token == "+")
                Stack.push(a + b);
            else if (token == "-")
                Stack.push(a - b);
            else if (token == "*")
                Stack.push(a * b);
            else if (token == "/")
                Stack.push(a / b);
        }
        else
        {
            std::cerr << "Erorr" << std::endl;
            return (1);
        }
    }
    std::cout << Stack.top() << std::endl;

    return (0);
}

// calculation steps for RPN:
// 1.Read the expression from left to right.
// 2.Push operands (numbers) onto a stack.
// 3.When an operator is encountered, pop the required number of operands from the stack.
// 4.Apply the operator to the operands.
// 5.Push the result back onto the stack.
// 6.Continue until the end of the expression.
// 7.The final result will be the only value left in the stack.
//