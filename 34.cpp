#include<iostream>
#include<string>
#include<algorithm>
#include<map>
using namespace std;

class Solution {
public:
    int FirstNotRepeatingChar(string str) {
        map<char, int> dict;
        for(int i=0; i<str.size(); i++)
            dict[str[i]]++;
        for(int i=0; i<str.size(); i++)
            if(dict[str[i]]==1)
                return i;
        return -1;
    }
};

int main()
{
    string str("aabbccd");
    Solution solution;
    cout<<solution.FirstNotRepeatingChar(str);
    return 0;
}
