#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> multiply(const vector<int>& A) {
        vector<int> res;
        if(A.empty())
            return res;
        res.push_back(1);
        for(int i=0; i<A.size(); i++)
            res.push_back(A[i]*res[i]);
        int tmp =1;
        for(int i=A.size()-1; i>=0; i--)
        {
            res[i] *= tmp;
            tmp *= A[i];
        }
        res.pop_back();
        return res;
    }
};

int main()
{
    int a[]={1,2,3,4,5,6};
    Solution solution;
    const vector<int> vec(a, a+6);
    vector<int> res = solution.multiply(vec);
    for(int i=0; i<res.size(); i++)
        cout<<res[i]<<" ";

    return 0;
}
