#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> res;
        if(num.empty())
            return res;
        int left=0;
        int length=num.size();
        while(left+size-1<length)
        {
            res.push_back(findMax(num, left, left+size-1));
            left+= 1;
        }
        return res;
    }
    int findMax(const vector<int>& num, int left, int right)
    {
        int max=num[left];
        for(int i =left+1; i<=right; i++)
            max = num[i]>max?num[i]:max;
        return max;
    }
};

int main()
{
    int a[]={2,3,4,2,6,2,5,1};
    vector<int> vec(a,a+8);
    Solution solution;
    vector<int> res = solution.maxInWindows(vec, 3);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";

    return 0;
}
