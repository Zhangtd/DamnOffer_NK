#include<iostream>
#include<map>
using namespace std;
class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        map<int, int> dict;
        for(int i=0; i<length; i++)
            dict[numbers[i]] += 1;
        cout<<dict[2]<<endl;
        for(int i=0; i<length; i++)
            if(dict[numbers[i]]!=1)
            {
                *duplication = numbers[i];
                cout<<*duplication<<endl;
                return true;
            }

        return false;
    }
};

int main()
{
    int a[] = {2,1,3,7,2,3,7};
    int *p = a+6;
    Solution solution;
    cout<<solution.duplicate(a, 7, p);
    return 0;
}
