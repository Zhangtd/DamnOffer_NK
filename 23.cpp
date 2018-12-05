#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if(sequence.empty())
            return false;

        return judge(0, sequence.size()-1, sequence);
    }
    bool judge(int left, int right, vector<int> seq)
    {
        if(left>=right)
            return true;
        int lSeql = left, rSeqr = right-1;
        int lSeqr = rSeqr, rSeql = rSeqr;
        for(; lSeqr>=lSeql; lSeqr--)
            if(seq[lSeqr]<seq[right])
                break;
        rSeql = lSeqr+1;
        for(int j=lSeql; j<=lSeqr; j++)
            if(seq[j]>seq[right])
            return false;
        return judge(lSeql, lSeqr, seq) && judge(rSeql, rSeqr, seq);
    }
};

int main()
{
    int a[] = {1,4,3,6,8,7,5};
    vector<int> vec(a, a+8);
    Solution solution;
    cout<<solution.VerifySquenceOfBST(vec);
    return 0;
}
