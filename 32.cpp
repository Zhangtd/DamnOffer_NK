#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool cmp(int a, int b)
    {
        string A="", B="";
        A += (to_string(a)+to_string(b));
        B += (to_string(b)+to_string(a));
        return  A<B;
    }
    string PrintMinNumber(vector<int> numbers) {
        string res;
        if(numbers.empty())
            return res;
        sort(numbers.begin(), numbers.end(), cmp);
        for(int i=0; i<numbers.size(); i++)
            res += to_string(numbers[i]);
        return res;
    }
};

int main()
{
    int a[]={3,32,321};
    vector<int> arr(a, a+3);
    Solution solution;
    cout<<solution.PrintMinNumber(arr);
    return 0;
}
