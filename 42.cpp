#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> FindNumbersWithSum(vector<int> array,int sum) {
        vector<int> res;
        if(array.empty())
            return res;
        int length = array.size();
        int i = 0;
        int j=length-1;
        int mul=100000;
        while(i<j)
        {
            if(array[i]+array[j]==sum)
            {
                if(array[i]*array[j]<mul)
                {

                    res.clear();
                    res.push_back(array[i]);
                    res.push_back(array[j]);
                    mul = array[i]*array[j];

                }
                i++;
                j--;
            }
            while(i<j && array[i]+array[j]<sum)   i++;
            while(i<j && array[i]+array[j]>sum)   j--;
        }
        return res;
    }
};

int main()
{
    int a[]={1,2,3,4,5,6};
    vector<int> arr(a, a+6);
    //cout<<arr[0];
    Solution solution;
    vector<int> res = solution.FindNumbersWithSum(arr, 7);
    cout<<res.size()<<endl;
    cout<<res[0]<<" "<<res[1];
    return 0;
}
