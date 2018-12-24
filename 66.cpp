#include<iostream>
using namespace std;

class Solution {
public:
    int movingCount(int threshold, int rows, int cols)
    {
        int* flag = new int[rows*cols]();
        return helper(0,0,rows, cols, flag, threshold);
    }
    int helper(int i, int j, int rows, int cols, int* flag, int threshold)
    {
        if(i<0||j<0||i>=rows||j>=cols||flag[i*cols+j]==1||digitSum(i,j)>threshold)
            return 0;
        flag[i*cols+j] = 1;
        return helper(i+1, j, rows, cols, flag, threshold)+
        helper(i-1, j, rows, cols, flag, threshold)+
        helper(i, j+1, rows, cols, flag, threshold)+
        helper(i, j-1, rows, cols, flag, threshold)+1;

    }
    int digitSum(int x, int y)
    {
        int sum = 0;
        while(x!=0)
        {
            sum += (x%10);
            x /= 10;
        }
        while(y!=0)
        {
            sum += (y%10);
            y /= 10;
        }
        return sum;
    }
};

int main()
{
    Solution solution;
    cout<<solution.digitSum(18, 10);
    return 0;
}
