#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
class Solution {
public:
    void FindNumsAppearOnce(vector<int> data,int* num1,int *num2) {
        vector<int> buff;
        sort(data.begin(), data.end());
        int length = data.size();
        if(data[0]!=data[1])
            buff.push_back(data[0]);
        if(data[length-1]!=data[length-2])
            buff.push_back(data[length-1]);
        for(int i=1; i<=length-2; i++)
            if(data[i-1]!=data[i] && data[i]!=data[i+1])
                buff.push_back(data[i]);

        //int i=buff[0], j=buff[1];
        //*num1 = buff[0];
        //*num2 = buff[1];
        cout<<buff.size()<<endl;
        cout<<buff[0]<<buff[1]<<endl;
    }
};
int main()
{
    int a[]={4,6,1,1,1,1};
    vector<int> arr(a, a+6);
    int *i=0, *j=0;
    Solution solution;
    solution.FindNumsAppearOnce(arr, i, j);
    cout<<i<<" "<<j;
    return 0;
}
