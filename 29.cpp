#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        vector<int> res;
        if(input.empty() || k>input.size())
            return res;
        sort(input.begin(), input.end());
        res.insert(res.begin(), input.begin(), input.begin()+k);
        return res;
    }
};

int main()
{
    int a[]={2,5,1,6,3,4};
    vector<int> arr(a, a+6);
    Solution solution;
    arr = solution.GetLeastNumbers_Solution(arr, 7);
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<" ";
    return 0;
}
