#include<iostream>
#include<vector>
#include<deque>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    int counter = 0;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL)
            return NULL;
    }

    TreeNode* LDR(TreeNode *root, int k)
    {

        if(counter+1==k)
            return root;

    }
};

int main()
{

    return 0;
}
