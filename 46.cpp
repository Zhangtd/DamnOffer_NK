#include<iostream>
using namespace std;

class Solution {
public:
    int LastRemaining_Solution(int n, int m)
    {
        int res=0, pre=0;
        if(n==1)
            return res;
        if(n==0)
            return -1;
        for(int i=2; i<=n; i++)
        {
            res = (pre+m)%i;
            pre = res;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    cout<<solution.LastRemaining_Solution(3,2);
    return 0;
}
