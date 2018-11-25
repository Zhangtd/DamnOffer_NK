#include<iostream>
using namespace std;
class Solution {
public:
    int Fibonacci(int n) {
        int a[50]={0};
        a[0]=0;
        a[1]=1;
        a[2]=1;
        for(int i=3; i<50; i++)
            a[i] = a[i-1]+a[i-2];
        return a[n];
    }

    int Fibonacci1(int n)
    {
        int pre2val = 0;
        int preval = 1;
        int val;

        if(n==0)
            return pre2val;
        if(n==1 || n==2)
            return preval;
        for(int i=2; i<=n; i++)
        {
            val = preval + pre2val;
            pre2val = preval;
            preval = val;
        }
        return val;
    }
};

int main()
{
    Solution solution;

    cout<<solution.Fibonacci1(5);
    return 0;
}
