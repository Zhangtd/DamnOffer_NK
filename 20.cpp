#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    stack<int> stack1, stack2;
    void push(int value) {
        stack1.push(value);
        if(stack2.empty())
            stack2.push(value);
        else if(stack2.top()>=value)
            stack2.push(value);
    }
    void pop() {
        int tmp = stack1.top();
        stack1.pop();
        if(tmp==stack2.top())
            stack2.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return stack2.top();
    }
};

int main()
{

    return 0;
}
