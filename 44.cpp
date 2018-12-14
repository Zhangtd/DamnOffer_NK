#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string ReverseSentence(string str) {
        string res, word;
        if(str.empty())
            return res;
        word.push_back(' ');
        for(int i=0; i<str.size(); i++)
        {
            if(str[i]==' ')
            {
                res = word + res;
                word.clear();
                word.push_back(' ');
            }
            else
                word.push_back(str[i]);
            //cout<<word<<endl;
        }
        res = word + res;
        res.erase(res.begin());
        return res;

    }
};

int main()
{
    string s="";
    Solution solution;
    cout<<solution.ReverseSentence(s);
    return 0;
}
