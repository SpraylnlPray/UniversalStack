#include "Stack.h"
#include <string>

class someClass
{
public:
    int test = 1;
    char test2 = 'a';
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
    float popped2 = *static_cast<float*>(stack.pop());
    int popped3 = *static_cast<int*>(stack.pop());

    someClass test;
    auto size = sizeof(test);
    stack.push(test);

    std::string myString = "asdf";
    stack.push(myString);
}
