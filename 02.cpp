#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool Find(int target, vector<vector<int>> array) {
        int i=array.size()-1;
        int cols = array[0].size();
        int j=0;
        if(array.empty())
            return false;
        while(i>=0 && j<cols)
        {
            if(array[i][j]==target)
                return true;
            if(array[i][j]>target)
                {i--;
                continue;}
            if(array[i][j]<target)
                {j++;
                continue;}
        }
        return false;
    }
};

int main()
{
    vector<int> row(10, 1);
    vector<vector<int>> array(10, row);
    Solution solution;
    bool res = solution.Find(1, array);

    cout<<res;
    return 0;
}


