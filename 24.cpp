#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
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
    vector<vector<int>> res;
    vector<int> tmpVec;

    bool cmp(vector<int> &x, vector<int> &y)
    {
        bool flag = x.size()<y.size();
        return flag;
    }

    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        if(root==NULL)
            return res;
        path_build(root, expectNumber);
        //sort(res.begin(), res.end(), cmp);
        return res;
    }

    void path_build(TreeNode* root, int sum_left)
    {
        tmpVec.push_back(root->val);
        if(sum_left==root->val && root->left==NULL && root->right==NULL)
            res.push_back(tmpVec);
        else
        {
            if(root->left!=NULL)
            path_build(root->left, sum_left-(root->val));
            if(root->right!=NULL)
            path_build(root->right, sum_left-(root->val));
        }

        tmpVec.pop_back();
    }

    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        TreeNode *tree = childTree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
        return tree;
    }
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

    void printVec(vector<vector<int>> vec){
    for(int i=0; i<vec.size(); i++)
    {
        for(int j=0; j<vec[i].size(); j++)
            cout<<vec[i][j]<<" ";
        cout<<endl;
    }

    }
};

int main()
{
    int p[] = {1,2,4,7,3,5,9,6,8,0};
    int v[] = {4,7,2,1,9,5,3,8,0,6};
    vector<int> pre(p, p+9);
    vector<int> vin(v, v+9);
    TreeNode* tree;
    vector<vector<int>> path;
    Solution solution;
    tree = solution.reConstructBinaryTree(pre, vin);
    solution.BFS(tree);
    path = solution.FindPath(tree, 18);
    solution.printVec(path);

    return 0;
}
