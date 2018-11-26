#include<iostream>
using namespace std;

class Solution {
public:
    int jumpFloorII(int number) {
        int pre = 1;
        if(number==0)
            return 0;
        if(number==1)
            return 1;
        int res;
        for(int i=2; i<=number; i++)
        {
            res = 2 * pre;
            pre = res;
        }
        return res;
    }
};

int main()
{
    Solution solution;
    cout<<solution.jumpFloorII(3);
    return 0;
}
