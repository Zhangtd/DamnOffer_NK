#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int GetNumberOfK(vector<int> data ,int k) {
        int res = 0;
        int flag = 0;
        if(data[0]<=data[data.size()-1])
            flag = 1;
        else
            flag = -1;
        for(int i=0; i<data.size(); i++)
        {
            if(data[i]==k)
                res += 1;
            else if(flag==1 && data[i]>k)
                break;
            else if(flag==-1 && data[i]<k)
                break;
        }
        return res;
    }
};

int main()
{
    int a[] = {1,2,3,3,3,4,4,5,7};
    vector<int> arr(a, a+9);
    Solution solution;
    cout<<solution.GetNumberOfK(arr, 0);
    return 0;
}
