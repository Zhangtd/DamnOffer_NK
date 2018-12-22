#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<int> stream;
    void Insert(int num)
    {
        vector<int>::iterator iter = stream.begin();
        for(; iter!=stream.end(); iter++)
            if(*iter>=num)
                break;
        stream.insert(iter, num);
    }

    double GetMedian()
    {
        int length = stream.size();
        if(length%2==0)
            return (stream[length/2]+stream[length/2-1])/2.0;
        else
            return stream[length/2];
    }

    void print()
    {
        for(int i=0; i<stream.size(); i++)
            cout<<stream[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    int a[]={1,3,2,4,1,6};
    Solution solution;
    for(int i=0; i<6; i++)
    {
        solution.Insert(a[i]);
        solution.print();
        cout<<solution.GetMedian()<<endl;
    }
    return 0;
}
