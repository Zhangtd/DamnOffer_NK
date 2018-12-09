#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
int FindGreatestSumOfSubArray(vector<int> array) {
        if(array.empty()) return 0;
        int sum = array[0], tempsum = array[0];
        for(int i = 1; i < array.size(); i++)
        {
            tempsum = (tempsum < 0) ? array[i] : tempsum + array[i];
            sum = (tempsum > sum) ? tempsum : sum;
        }
        return sum;
    }

};

int main()
{
    int a[] = {6,-3,-2,7,-15,1,2,2};
    vector<int> arr(a, a+8);
    Solution solution;
    cout<<solution.FindGreatestSumOfSubArray(arr);
    return 0;
}
