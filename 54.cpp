#include<iostream>
#include<string>
using namespace std;

class Solution
{
public:
    string s;
    int ct[256]={0};
  //Insert one char from stringstream
    void Insert(char ch)
    {
         s += ch;
         ct[ch] ++;
    }
  //return the first appearence once char in current stringstream
    char FirstAppearingOnce()
    {
        for(int i=0; i<s.size(); i++)
            if(ct[s[i]]==1)
                return s[i];
        return '#';
    }

};

int main()
{
    char s[]="google";
    Solution solution;
    for(int i=0; i<6; i++)
    {
        solution.Insert(s[i]);
        cout<<solution.FirstAppearingOnce()<<endl;;
    }
    return 0;
}
