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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if(!pRootOfTree)
            return NULL;
        TreeNode* head;
        head = Tree2List(pRootOfTree, 1);
        return head;
    }

    TreeNode* Tree2List(TreeNode* tree, bool flag)
    {
        TreeNode* subHead;
        if(tree->left!=NULL)
        {
            subHead = Tree2List(tree->left, 0);
            if(subHead!=NULL)
                subHead->right = tree;
            tree->left = subHead;
        }
        if(tree->right!=NULL)
        {
            subHead = Tree2List(tree->right, 1);
            if(subHead!=NULL)
                subHead->left = tree;
            tree->right = subHead;
        }
        if(tree->right==NULL && tree->left==NULL)
            return tree;
        if(flag)
            while(subHead->left!=NULL)
                subHead = subHead->left;
        else
            while(subHead->right!=NULL)
                subHead = subHead->right;
        return subHead;
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

void printList(TreeNode* head)
{
    TreeNode* node = head;
    cout<<node->val<<" ";
    while(node->right)
    {
        node = node->right;
        cout<<node->val<<" ";
    }
    cout<<endl;
}

int main()
{
    int p[] = {5,3,1,2,4,7,6,8};
    int v[] = {1,2,3,4,5,6,7,8};
    vector<int> pre(p, p+8);
    vector<int> vin(v, v+8);
    TreeNode* tree = reConstructBinaryTree(pre, vin);
    BFS(tree);
    Solution solution;
    TreeNode* head;
    head = solution.Convert(tree);
    cout<<"New List:"<<endl;
    printList(head);
    return 0;
}
