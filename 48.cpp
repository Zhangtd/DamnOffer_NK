#include<iostream>
using namespace std;

class Solution {
public:
    int Add(int num1, int num2)
    {
        while(num2!=0)
        {
            int tmp = num1 ^ num2;
            num2 = (num1&num2)<<1;
            num1 = tmp;
        }
        return num1;
    }
};

int main()
{
    Solution solution;
    cout<<solution.Add(3,4);
    return 0;
}