#include<iostream>
using namespace std;

class Solution {
public:
    int rectCover(int number) {
        int rect1 = 1;
        int rect2 = 2;
        if(number==1)
            return 1;
        if(number==2)
            return 2;
        int res = 0;
        for(int i=3; i<=number; i++)
        {
            res = rect1 + rect2;
            rect1 = rect2;
            rect2 = res;
        }
        return res;

    }
};

int main()
{
    Solution solution;
    cout<<solution.jumpFloor(4);
    return 0;
}
