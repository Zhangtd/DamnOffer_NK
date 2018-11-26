#include<iostream>
using namespace std;
class Solution {
public:
    int jumpFloor(int number) {
        int floor1 = 1;
        int floor2 = 2;
        if(number==1)
            return floor1;
        if(number==2)
            return floor2;
        int f_1 = floor2;
        int f_2 = floor1;
        int res = 0;
        for(int i=3; i<=number; i++)
        {
            res = f_1 + f_2;
            f_2 = f_1;
            f_1 = res;
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
