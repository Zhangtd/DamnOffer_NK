#include<iostream>
#include<stack>
using namespace std;

class Solution
{
public:
    void push(int node) {
        int tmp=0;
        if(stack1.empty())
        {
            if(!stack2.empty())
            {
                while(!stack2.empty())
                {
                    tmp = stack2.top();
                    stack1.push(tmp);
                    stack2.pop();
                }
            }
        }
        stack1.push(node);
    }

    int pop() {
        int pre = 0;
        int tmp = 0;
        if(stack2.empty())
        {
            if(!stack1.empty())
            {
                while(!stack1.empty())
                {
                    tmp = stack1.top();
                    stack2.push(tmp);
                    stack1.pop();
                }
            }
        }
        pre = stack2.top();
        stack2.pop();
        return pre;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    int a[] = {1,2,3,4,5,6};
    Solution solution;
    for(int i=0; i<3; i++)
        solution.push(a[i]);
    cout<<solution.pop()<<endl;
    cout<<solution.pop()<<endl;
    solution.push(10);
    cout<<solution.pop()<<endl;
    solution.push(20);
    cout<<solution.pop()<<endl;
    cout<<solution.pop()<<endl;
    solution.push(30);
    cout<<solution.pop()<<endl;
    return 0;
}
