#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        if(numbers.empty())
            return 0;
        if(numbers.size()==1)
            return numbers[0];
        sort(numbers.begin(), numbers.end());
        int counter = 1;
        int pre = numbers[0];
        int res = 0;
        for(int i=1; i<numbers.size(); i++)
        {
            if(numbers[i]==pre)
            {
                counter+=1;
            }
            else
            {
                counter = 1;
                pre = numbers[i];
            }
            if(counter>numbers.size()/2)
                res = numbers[i];
        }
        return res;
    }
};

int main()
{
    int a[]={1,2,3,4,5};
    vector<int> arr(a, a+5);
    Solution solution;
    cout<<solution.MoreThanHalfNum_Solution(arr);
    return 0;
}
