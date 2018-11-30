#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        vector<int> res;

        for(vector<int>::iterator iter=array.begin(); iter!=array.end(); iter++)
            if(*iter%2!=0)
                res.push_back(*iter);
        for(vector<int>::iterator iter=array.begin(); iter!=array.end(); iter++)
            if(*iter%2==0)
                res.push_back(*iter);
        array = res;
    }
};

int main()
{
    vector<int> a;
    vector<int> res;
    for(int i=-10; i<10; i++)
        a.push_back(i);
    Solution solution;
    solution.reOrderArray(a);
    for(vector<int>::iterator iter=a.begin(); iter!=a.end(); iter++)
        cout<<*iter<<endl;
    return 0;
}
