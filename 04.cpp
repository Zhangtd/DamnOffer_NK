#include<iostream>
#include<vector>
using namespace std;


// Definition for binary tree
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        TreeNode *tree = childTree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
        return tree;
    }
//private:
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
};
class Test{
public:
    void preWalk(TreeNode *root){
        if(root==NULL)
            return;
        cout<<root->val<<endl;
        preWalk(root->left);
        preWalk(root->right);
    }

    void inWalk(TreeNode *root){
    if(root==NULL)
        return;
    priorWalk(root->left);
    cout<<root->val<<endl;
    priorWalk(root->right);
    }

    void priorWalk(TreeNode *root){
    if(root==NULL)
        return;
    priorWalk(root->left);
    priorWalk(root->right);
    cout<<root->val<<endl;
    }
};

int main()
{
    vector<int> pre;
    vector<int> vin;
    //int p[] = {1,2,4,7,3,5,6,8};
    //int v[] = {4,7,2,1,5,3,8,6};
    int p[] = {1,2,3,4,5,6,7};
    int v[] = {3,2,4,1,6,5,7};

    for(int i=0; i<7; i++){
        pre.push_back(p[i]);
        vin.push_back(v[i]);
    }
    Solution solution;
    TreeNode *T = solution.reConstructBinaryTree(pre, vin);
    Test aTest;
    aTest.preWalk(T);

    return 0;
}
