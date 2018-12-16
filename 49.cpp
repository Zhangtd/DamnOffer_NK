#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int StrToInt(string str) {
        int res=0;
        int flag = 0;
        if(str.empty())
            return 0;
        if(str[0]=='+')
            flag = 1;
        else if(str[0]=='-')
            flag = -1;
        else if(!(str[0]>='0'&&str[0]<='9'))
            return 0;
        else
            res = str[0]-'0';

        if(flag!=0 && str.size()==1)
            return 0;
        //cout<<res<<endl;
        for(int i=1; i<str.size(); i++)
        {
            if(str[i]>='0'&&str[i]<='9')
            {
                res *= 10;
                res += (str[i]-'0');
            }
            else
                return 0;
        }
        if(flag)
            res = flag*res;
        return res;
    }
};

int main()
{
    string s="-0ddd.1101";
    Solution solution;
    cout<<solution.StrToInt(s);
    return 0;
}
