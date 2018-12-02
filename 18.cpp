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
    void Mirror(TreeNode *pRoot) {
        if(pRoot == NULL)
            return;
        TreeNode *tmp;
        tmp = pRoot->right;
        pRoot->right = pRoot->left;
        pRoot->left = tmp;
        Mirror(pRoot->left);
        Mirror(pRoot->right);

    }
};

class treeOp
{
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

    void BFS(TreeNode *root){
     vector<TreeNode*> nodeQue;
     int top = 0;
     int bottom = 0;

     nodeQue.push_back(root);
     bottom++;
     while(top!=bottom)
     {
         cout<<nodeQue[top]->val<<" ";
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
     cout<<endl;
     cout<<"This tree has "<<nodeQue.size()<<" nodes."<<endl;
    }
};

int main()
{
    vector<int> pre;
    vector<int> vin;
    int p[] = {1,2,4,7,3,5,6,8};
    int v[] = {4,7,2,1,5,3,8,6};

    pre.insert(pre.end(), p, p+8);
    vin.insert(vin.end(), v, v+8);
    treeOp operation;
    TreeNode *T = operation.reConstructBinaryTree(pre, vin);
    operation.BFS(T);
    Solution solution;
    solution.Mirror(T);
    operation.BFS(T);

    return 0;
}
