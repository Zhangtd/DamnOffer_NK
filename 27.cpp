#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<string> resVec;
    vector<string> Permutation(string str) {
        sort(str.begin(), str.end());
        if(!str.empty())
            subStrGen(0, str);
        return resVec;

    }

    void subStrGen(int k, string str)
    {
        if(k==str.size()-1)
            resVec.push_back(str);
        for(int i=k; i<str.size(); i++)
        {
            if(str[i]==str[k] && i!=k)
                continue;
            swap(str[i], str[k]);
            subStrGen(k+1, str);
        }
    }
};

int main()
{
    string s("adcab");
    cout<<s<<endl;
    sort(s.begin(), s.end());
    cout<<s<<endl;
    Solution solution;
    vector<string> arr = solution.Permutation(s);
    for(int i=0; i<arr.size(); i++)
        cout<<arr[i]<<endl;
    cout<<arr.size();
    return 0;
}
