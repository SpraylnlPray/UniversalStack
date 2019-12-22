#include <iostream>
#include "Stack.h"
#include <string>

class someClass
{
public:
    int test;
    char test2;
};

int main()
{
    Stack<100> stack;
    bool isFull = stack.isFull();
    bool isEmpty = stack.isEmpty();

    bool push = stack.push(1);
    bool push1 = stack.push(2.1f);
    bool push2 = stack.push(true);    

    bool peeked = stack.peek();

    bool popped = stack.pop();
    float* popped2 = static_cast<float*>(stack.pop());
    int* popped3 = static_cast<int*>(stack.pop());

    push = stack.push(1);

     isEmpty = stack.isEmpty();
    std::string myString = "asdf";
    stack.push(myString); // crashes somehow

    std::cout << "Hello World!\n";
}
