#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string LeftRotateString(string str, int n) {
        string tmp_s;
        char tmp_c;
        if(str.empty())
            return tmp_s;
        if(n>str.size())
            n=n%str.size();
        for(int i=0; i<n; i++)
        {
            tmp_c = str[0];
            str.erase(str.begin());
            cout<<str<<endl;
            str.push_back(tmp_c);
        }
        return str;
    }
};

int main()
{
    string s = "abcdefg";
    Solution solution;
    cout<<solution.LeftRotateString(s, 9);
    return 0;
}
