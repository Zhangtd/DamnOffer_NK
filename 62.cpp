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
    TreeNode* res = NULL;
    TreeNode* KthNode(TreeNode* pRoot, int k)
    {
        if(pRoot==NULL)
            return NULL;
        LDR(pRoot, k);
        return res;
    }

    void LDR(TreeNode *root, int k)
    {
        if(root==NULL)
            return ;
        LDR(root->left, k);
        if(++counter==k)
        {
            res = root;
            return;
        }
        LDR(root->right, k);
    }
};

int main()
{

    return 0;
}
