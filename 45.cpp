#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool IsContinuous( vector<int> numbers ) {
        if(numbers.size()!=5)
            return false;
        sort(numbers.begin(), numbers.end());
        int max=numbers[numbers.size()-1], min=0;
        for(int i=0; i<numbers.size()-1; i++)
        {
            if(numbers[i]!=0)
            {
                min= numbers[i];
                break;
            }
        }
        for(int i=0; i<numbers.size()-1; i++)
            if(numbers[i]!=0 && numbers[i]==numbers[i+1])
                return false;
        if(max-min>=5)
            return false;
        else
            return true;
    }
};

int main()
{
    int a[]={1,2,3,4,6};
    vector<int> arr(a, a+5);
    Solution solution;
    cout<<solution.IsContinuous(arr);
    return 0;
}
