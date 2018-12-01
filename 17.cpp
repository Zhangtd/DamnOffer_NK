#include<iostream>
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
    bool isSubtree(TreeNode* root1, TreeNode* root2)
    {
        if(root1==NULL)
            return false;
        if(root2==NULL)
            return true;
        if(root1->val == root2->val)
            return isSubtree(root1->left, root2->left) ||
                isSubtree(root1->right, root2->right);
        else
            return false;
    }
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2)
    {
        if(pRoot1==NULL || pRoot2==NULL)
            return false;
        return (HasSubtree(pRoot1->left, pRoot2)) ||
                (HasSubtree(pRoot1->right, pRoot2)) ||
                (isSubtree(pRoot1, pRoot2));
    }

};
