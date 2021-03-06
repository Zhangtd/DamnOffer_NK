#include<iostream>
#include<vector>
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
    int TreeDepth(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return 0;
        int depth = toLeaf(pRoot);
        return depth;
    }

    int toLeaf(TreeNode* root)
    {
        int length = 1;
        int len_left = 0;
        int len_right = 0;
        if(root->left!=NULL)
            len_left = toLeaf(root->left);
        if(root->right!=NULL)
            len_right = toLeaf(root->right);
        //cout<<len_left<<len_right<<endl;
        length += (len_left>=len_right?len_left:len_right);

        return length;
    }
};
TreeNode* childTree(vector<int> pre, vector<int> vin, int pre_l, int pre_r, int vin_l, int vin_r){
        if(pre_l>pre_r || vin_l>vin_r)
            return NULL;
        int nodeVal = pre[pre_l];
        TreeNode *newNode = new TreeNode(nodeVal);
        int loc = vin_l;
        for(; loc<=vin_r; loc++)
            if(vin[loc] == nodeVal)
                break;
        int length = loc - vin_l;
        newNode->left = childTree(pre, vin, pre_l+1, pre_l+length, vin_l, loc-1);
        newNode->right = childTree(pre, vin, pre_l+length+1, pre_r, loc+1, vin_r);
        return newNode;
    }
TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        TreeNode *tree = childTree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
        return tree;
    }

int main()
{
    int p[] = {1,2,4,7,3,5,6,8};
    int v[] = {4,7,2,1,5,3,8,6};
    vector<int> pre(p, p+8);
    vector<int> vin(v, v+8);
    TreeNode* T = reConstructBinaryTree(pre, vin);
    Solution solution;
    cout<<solution.TreeDepth(T);
    return 0;
}
