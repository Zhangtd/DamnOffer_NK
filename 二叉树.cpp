#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct treeNode
{
    int val;
    struct treeNode *left;
    struct treeNode *right;
    treeNode(int x):
        val(x), left(NULL), right(NULL){
        }
};

class treeOp
{
public:
    treeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        treeNode *tree = childTree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
        return tree;
    }
//private:
    treeNode* childTree(vector<int> pre, vector<int> vin, int pre_l, int pre_r, int vin_l, int vin_r){
        if(pre_l>pre_r || vin_l>vin_r)
            return NULL;
        int nodeVal = pre[pre_l];
        treeNode *newNode = new treeNode(nodeVal);
        int loc = vin_l;
        for(; loc<=vin_r; loc++)
            if(vin[loc] == nodeVal)
                break;
        int length = loc - vin_l;
        newNode->left = childTree(pre, vin, pre_l+1, pre_l+length, vin_l, loc-1);
        newNode->right = childTree(pre, vin, pre_l+length+1, pre_r, loc+1, vin_r);
        return newNode;
    }

    void BFS(treeNode *root){
     vector<treeNode*> nodeQue;
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

    void DFS(treeNode *root)
    {
        stack<treeNode*> nodeStack;
        nodeStack.push(root);
        while(!nodeStack.empty())
        {
            treeNode* node = nodeStack.top();
            cout<<node->val<<" ";
            nodeStack.pop();
            if(node->right)
                nodeStack.push(node->right);
            if(node->left)
                nodeStack.push(node->left);
        }
    }

    void preWalk(treeNode *root){
        if(root==NULL)
            return;
        cout<<root->val<<endl;
        preWalk(root->left);
        preWalk(root->right);
    }

    void inWalk(treeNode *root){
    if(root==NULL)
        return;
    priorWalk(root->left);
    cout<<root->val<<endl;
    priorWalk(root->right);
    }

    void priorWalk(treeNode *root){
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
    int p[] = {1,2,4,7,3,5,6,8};
    int v[] = {4,7,2,1,5,3,8,6};
//    int p[] = {1,2,3,4,5,6,7};
//    int v[] = {3,2,4,1,6,5,7};

    for(int i=0; i<8; i++){
        pre.push_back(p[i]);
        vin.push_back(v[i]);
    }
    treeOp operation;
    treeNode *T = operation.reConstructBinaryTree(pre, vin);
    operation.DFS(T);

    return 0;
}

