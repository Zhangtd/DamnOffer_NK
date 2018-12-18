#include<iostream>
#include<vector>
using namespace std;

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        vector<ListNode*> addr;
        ListNode* node=pHead;
        while(node->next!=NULL)
        {
            if(judge(node, addr))
                return node;
            else
            {
                addr.push_back(node);
                node = node->next;
            }
        }
        return NULL;
    }
    bool judge(ListNode* a, vector<ListNode*> address)
    {
        for(int i=0; i<address.size(); i++)
            if(a==address[i])
                return true;
        return false;
    }
};

int main()
{
    int i=0;
    int *p=&i;
    cout<<p<<endl;
    return 0;
}
