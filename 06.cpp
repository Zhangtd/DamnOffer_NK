#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minNumberInRotateArray(vector<int> rotateArray) {
        if(rotateArray.empty())
            return 0;
        for(size_t i=0; i<rotateArray.size()-1; i++)
        {
            if(rotateArray[i]>rotateArray[i+1])
                return rotateArray[i+1];
        }
        return rotateArray[0];
    }
};

int main()
{
    int a[] = {2,6,6,6,1,2};
    int b[] = {1,2,3,4,5,1};
    vector<int> A(b, b+6);
    Solution solution;

    cout<<solution.minNumberInRotateArray(A);
    return 0;
}
