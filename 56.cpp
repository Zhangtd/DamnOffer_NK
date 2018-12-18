#include<iostream>
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
    ListNode* deleteDuplication(ListNode* pHead)
    {
        if(pHead==NULL)
            return pHead;
        ListNode *bnode, *fnode;
        ListNode *fHead = new ListNode(0);
        bnode = pHead;
        fHead->next = bnode;
        if(bnode->next!=NULL)
        {
            fnode = bnode->next;
            int tmp = bnode->val;
            if(tmp!=fnode->val)
                bnode->next = deleteDuplication(bnode->next);
            else
            {
                while(fnode->next!=NULL && fnode->val==tmp)
                    fnode = fnode->next;
                fnode = fnode->next;
                fHead->next = deleteDuplication(fnode->next);
            }
        }

        return fHead->next;
    }
};
void visit(ListNode* pHead)
{
    ListNode* node = pHead;
    cout<<node->val<<" ";
    while(node->next!=NULL)
    {
        node = node->next;
        cout<<node->val<<" ";
    }
    cout<<endl;
}
int main()
{
    int a[]={1,2,3,3,4,4,5};
    ListNode* head = new ListNode(a[0]);
    ListNode* node = head;
    for(int i=1; i<=6; i++)
    {
        ListNode* tmp = new ListNode(a[i]);
        node->next = tmp;
        node = node->next;
    }
    visit(head);
    Solution solution;
    node = solution.deleteDuplication(head);
    visit(node);
    return 0;
}
