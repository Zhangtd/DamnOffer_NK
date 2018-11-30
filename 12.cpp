#include<iostream>
using namespace std;
class Solution {
public:
    double Power(double base, int exponent) {
    double res = 1;
    int r = (exponent>0)? exponent: -exponent;
    if(base==0)
        return 0;
    while(r !=  0)
    {
        if(r&1!=0)
            res*=base;
        base*=base;
        r>>=1;
    }
    if(exponent<0)
        res = 1/res;
    return res;
    }
};

int main()
{
    Solution solution;
    cout<<solution.Power(2, -2)<<endl;
    return 0;
}
