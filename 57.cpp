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
        if(pNode->next==NULL)
            return pNode->right;
        if(pNode->right!=NULL)
            return pNode->right;
        if(pNode->right==NULL)
        {
            if(pNode == pNode->next->left)
                return pNode->next;
            else if(pNode==pNode->next->right)
            {
                pNode->next->right = NULL;
                return GetNext(pNode->next);
            }
        }
        return NULL;
    }
};

int main()
{
    return 0;
}
