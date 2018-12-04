#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool IsPopOrder(vector<int> pushV,vector<int> popV) {
        if(pushV.empty())
            return false;
        vector<int> s;
        for(int i=0, j=0; i<pushV.size(); i++)
        {
            s.push_back(pushV[i]);
            while(j<popV.size() && popV[j]==s.back())
            {
                s.pop_back();
                j++;
            }
        }
        return s.empty();
    }
};

int main()
{
    int pushArr[] = {1, 2, 3, 4, 5, 6};
    int popArr[] = {4, 6, 5, 3, 2, 1};
    vector<int> pushVec(pushArr, pushArr+6);
    vector<int> popVec(popArr, popArr+6);
    Solution solution;
    cout<<solution.IsPopOrder(pushVec, popVec);
    return 0;
}
