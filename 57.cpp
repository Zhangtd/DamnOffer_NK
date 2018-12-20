#include<iostream>
#include<vector>
using namespace std;


struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {

    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if(pNode==NULL)
            return NULL;
        if(pNode->right!=NULL)
        {
            pNode = pNode->right;
            while(pNode->left!=NULL)
                pNode = pNode->left;
            return pNode;
        }
        while(pNode->next != NULL)
        {
            TreeLinkNode *proot = pNode->next;
            if(proot->left==pNode)
                return proot;
            proot = pNode->next;
        }

        return NULL;
    }
};

int main()
{
    return 0;
}
