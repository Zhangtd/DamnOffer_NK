#include<iostream>
using namespace std;

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str== NULL || length <0)
            return ;
        int old_length = 0;
        int new_length = 0;
        int i = 0;
        while(*(str+i)!='\0')
        {
            old_length += 1;
            new_length += 1;
            if(*(str+i)==' ')
            {
                new_length += 2;
            }
            i += 1;
        }
        if(new_length > length)
            return ;
        int old_index = old_length;
        int new_index = new_length;
        while(old_index >= 0 && new_index >= old_index)
        {
            if(str[old_index]==' ')
            {
                str[new_index--] = '0';
                str[new_index--] = '2';
                str[new_index--] = '%';
            }
            else
            {
                str[new_index--] = str[old_index];
            }
            old_index --;
        }

    }
};

int main()
{
    char str[20]="hello world.";
    Solution solution;
    solution.replaceSpace(str, 20);
    cout<<str<<endl;
    return 0;
}
