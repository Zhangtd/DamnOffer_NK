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
        vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if(pRoot==NULL)
            return res;
        vector<vector<TreeNode*> > buff;
        vector<TreeNode*> tmp_buff;
        tmp_buff.push_back(pRoot);
        buff.push_back(tmp_buff);
        int level_num = buff.size();
        //cout<<"ready to dive"<<endl;
        for(int i=0; i!=level_num; i++)
        {
            vector<TreeNode*> tmp_buff;
            vector<int> tmp_array;
            for(int j=0; j<=buff[i].size()-1; j++)
            {
                tmp_array.push_back(buff[i][j]->val);
                if(buff[i][j]->left!=NULL)
                    tmp_buff.push_back(buff[i][j]->left);
                if(buff[i][j]->right!=NULL)
                    tmp_buff.push_back(buff[i][j]->right);
            }
            if(!tmp_buff.empty())    buff.push_back(tmp_buff);
            res.push_back(tmp_array);
            level_num =  buff.size();
        }
        return res;
        }

};
void printVec(vector<vector<int> > arr)
{
    for(int i=0; i!=arr.size(); i++)
    {
        for(int j=0; j!=arr[i].size(); j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

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

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if(pre.empty()||vin.empty())
            return NULL;
        TreeNode *tree = childTree(pre, vin, 0, pre.size()-1, 0, vin.size()-1);
        return tree;
    }
//private:


int main()
{
    int p[] = {1,2,4,10,7,3,5,9,6,8,11};
    int v[] = {10,4,7,2,1,9,5,3,8,6,11};
    vector<int> pre(p, p+11);
    vector<int> vin(v, v+11);
    TreeNode* tree=reConstructBinaryTree(pre, vin);
    cout<<"tree constructed."<<endl;
    Solution solution;
    vector<vector<int> > arr = solution.Print(tree);
    printVec(arr);
    return 0;
}
