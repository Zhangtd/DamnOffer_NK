#include<iostream>
using namespace std;
class Solution {
public:
     int  NumberOf1(int n) {
         int res = 0;
         while(n!=0)
         {
             res++;
             n = n & (n-1);
         }
         return res;
     }
};
int main()
{
    Solution solution;

    cout<<solution.NumberOf1(5);
    return 0;
}
