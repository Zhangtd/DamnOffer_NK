#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int InversePairs1(vector<int> data) {  //±©Á¦½â·¨ O(n^2)
        int counter = 0;
        for(int i=0; i<data.size()-1; i++)
            for(int j=i+1; j<data.size(); j++)
                if(data[i]>data[j])
                    counter += 1;
        if(counter>=1000000007)
            return counter%1000000007;
        return counter;
    }

    int InversePairs(vector<int> data) {
        int length = data.size();
        if(length==0)
            return 0;

        vector<int> data_copy(data.begin(), data.end());
        long long counter = mergeMethod(data, data_copy, 0, length-1);
        return counter%1000000007;
    }

    long long mergeMethod(vector<int> &data, vector<int> &data_copy, int left, int right)
    {
        if(left==right)
        {
            data_copy[left] = data[left];
            return 0;
        }

        int length = (right-left)/2;

        long long sub_left = mergeMethod(data_copy, data, left, left+length);
        long long sub_right = mergeMethod(data_copy, data, left+length+1, right);

        int i = left+length, j=right;
        int copy_index = right;
        long long counter = 0;

        while(i>=left && j>=left+length+1)
        {
            if(data[i]>data[j])
            {
                counter = counter + (j-left-length);
                data_copy[copy_index--] = data[i--];
            }
            else
                data_copy[copy_index--] = data[j--];
        }
        for(; i>=left; i--)
            data_copy[copy_index--] = data[i];
        for(; j>=left+length+1; j--)
            data_copy[copy_index--] = data[j];


        return counter + sub_left + sub_right;
    }
};

int main()
{
    Solution solution;
    vector<int> arr;
    for(int i=1; i<=7; i++)
        arr.push_back(i);
    arr.push_back(0);
    cout<<solution.InversePairs(arr);
    return 0;
}
