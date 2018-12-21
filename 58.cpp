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
    bool isSymmetrical(TreeNode* pRoot)
    {
        if(pRoot==NULL)
            return true;
        return isEqual(pRoot->left, pRoot->right);
    }
    bool isEqual(TreeNode* L, TreeNode* R)
    {
        //cout<<L->val<<" "<<R->val<<endl;
        //cout<<(L->val==R->val)<<endl;
        if(L==NULL && R==NULL)
            return true;
        if(R==NULL || L==NULL)
            return false;
        if(L->val!=R->val)
            return false;
        else
            return isEqual(L->left, R->right) && isEqual(L->right, R->left);
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

void BFS(TreeNode *root){
     vector<TreeNode*> nodeQue;
     int top = 0;
     int bottom = 0;

     nodeQue.push_back(root);
     bottom++;
     while(top!=bottom)
     {
         cout<<nodeQue[top]->val<<endl;
         if(nodeQue[top]->left!=NULL)
         {
             nodeQue.push_back(nodeQue[top]->left);
             bottom++;
         }
         if(nodeQue[top]->right!=NULL)
         {
             nodeQue.push_back(nodeQue[top]->right);
             bottom++;
         }
         top++;
     }
     cout<<"This tree has "<<nodeQue.size()<<" nodes."<<endl;
    }

int main()
{
    int p[]={8,6,5,7,6,7,5};
    int v[]={5,6,7,8,7,6,5};
    vector<int> pre(p, p+7);
    vector<int> vin(v, v+7);
    TreeNode* tree = reConstructBinaryTree(pre, vin);
    BFS(tree);
    Solution solution;
    cout<<solution.isSymmetrical(tree);
    return 0;
}
