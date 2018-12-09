#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int NumberOf1Between1AndN_Solution(int n)
    {
        int counter = 0;
        for(int m=1; m<=n; m*=10)
        {
            int a = n/m;
            int b = n%m;
            if(a%10==0)
                counter+=a/10*m;
            else if(a%10==1)
                counter+=(a/10*m)+(b+1);
            else
                counter+=(a/10+1)*m;
        }
        return counter;
    }
};

int main()
{
    Solution solution;
    cout<<solution.NumberOf1Between1AndN_Solution(105);
    return 0;
}
