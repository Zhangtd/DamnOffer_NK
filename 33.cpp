#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int GetUglyNumber_Solution1(int index) {
    int ugly[10000] = {1};
    int counter = 1;
    int buff_2 =0, buff_3=0, buff_5=0;
    while(true)
    {
        for(int i =0; i<counter; i++)
            if(ugly[i]*2>ugly[counter-1])
            {
                buff_2 = ugly[i]*2;
                break;
            }
        for(int i=0; i<counter; i++)
            if(ugly[i]*3>ugly[counter-1])
        {
            buff_3 = ugly[i]*3;
            break;
        }
        for(int i=0; i<counter; i++)
            if(ugly[i]*5>ugly[counter-1])
        {
            buff_5 = ugly[i]*5;
            break;
        }
        ugly[counter] = min(min(buff_2, buff_3), buff_5);
        counter++;
        if(counter==index)
            break;
    }
        return ugly[counter-1];
    }

    int GetUglyNumber_Solution(int index) {
        vector<int> arr;
        arr.push_back(1);
        int p2=0, p3=0, p5=0, newNum=1;
        while(arr.size()<index)
        {
            newNum = min(min(arr[p2]*2, arr[p3]*3), arr[p5]*5);
            if(newNum == arr[p2]*2) p2++;
            if(newNum == arr[p3]*3) p3++;
            if(newNum == arr[p5]*5) p5++;
            arr.push_back(newNum);
        }
        return arr[index-1];
    }
};

int main()
{
    Solution solution;
    cout<<solution.GetUglyNumber_Solution(10);
    return 0;
}
