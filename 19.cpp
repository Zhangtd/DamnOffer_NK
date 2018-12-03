#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> output_array;
        if(matrix.empty())
            return output_array;
        int left = 0, right = matrix.size()-1;
        int top = 0, bottom = matrix[0].size()-1;
        while(left<=right && top<=bottom)
        {
            for(int i=left; i<=right; i++)
                output_array.push_back(matrix[top][i]);
            top += 1;
            for(int i=top; i<=bottom; i++)
                output_array.push_back(matrix[i][right]);
            right -= 1;
            for(int i=right; i>=left; i--)
                output_array.push_back(matrix[bottom][i]);
            bottom -= 1;
            for(int i=bottom; i>=top; i--)
                output_array.push_back(matrix[i][left]);
            left += 1;
        }
        return output_array;
    }
};

int main()
{
    vector<vector<int>> mat;
    for(int i=0; i<3; i++)
    {
        vector<int> arr;
        for(int j=1; j<=3; j++)
            arr.push_back(i*3+j);
        mat.push_back(arr);
    }
    vector<int> res;
    Solution solution;
    res = solution.printMatrix(mat);
    for(vector<int>::iterator iter=res.begin(); iter!=res.end(); iter++)
        cout<<*iter<<" ";

    return 0;
}
