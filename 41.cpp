#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > FindContinuousSequence(int sum) {
        vector<vector<int>> res;
        if(sum<=0)
            return res;
        int t =0;

        for(int i=2; i<=sum/2+1; i++)
        {
            t = solve(sum, i);
            if(t)
            {
                vector<int> tmp;
                for(int j=t; j<t+i; j++)
                    tmp.push_back(j);
                res.push_back(tmp);
            }
        }
        vector<vector<int>> res_;
        for(int i=0; i<res.size(); i++)
            res_.insert(res_.begin(), res[i]);
        return res_;
    }

    int solve(int N, int num)
    {
        int sub = (num-1)*num/2;
        if((N-sub)%num || N<=sub)
            return 0;
        else
            return (N-sub)/num;
    }
};

int main()
{
    vector<vector<int>> arr;
    Solution solution;
    arr = solution.FindContinuousSequence(100);
    //cout<<solution.solve(100, 5)<<endl;
    for(int i=0; i<arr.size(); i++)
    {
        for(int j=0; j<arr[i].size(); j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
