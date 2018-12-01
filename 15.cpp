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
    ListNode* ReverseList1(ListNode* pHead) {
    if(pHead == NULL)
        return NULL;
    int a[10000], i=0;
    a[i++] = pHead->val;
    while(pHead->next != NULL)
    {
        pHead = pHead->next;
        a[i++] = pHead->val;
    }
    ListNode *newHead = new ListNode(a[--i]);
    ListNode *n = newHead;
    while(i>0)
    {
        ListNode *node = new ListNode(a[i-1]);
        n->next = node;
        n = node;
        i--;
    }
    return newHead;
    }

    ListNode* ReverseList(ListNode* pHead) {
    if(pHead == NULL)
        return NULL;
    ListNode *newHead = NULL;
    ListNode *pNode = NULL;
    ListNode *pPre = NULL;

    pNode = pHead;
    while(pNode!=NULL)
    {
        ListNode *pNext = pNode->next;
        if(pNext==NULL)
            newHead = pNode;
        pNode->next = pPre;
        pPre = pNode;
        pNode = pNext;
    }
    return newHead;
    }
};

int main()
{
    ListNode *head = new ListNode(0);
    ListNode *node = new ListNode(1);
    head->next = node;
    for(int i=2; i<=10; i++)
    {
        ListNode *node1 = new ListNode(i);
        node->next = node1;
        node = node1;
    }
//    cout<<head->val<<" ";
//    while(head->next != NULL)
//    {
//        head = head->next;
//        cout<<head->val<<" ";
//    }
//    cout<<endl;
    Solution solution;
    ListNode *newHead;
    newHead = solution.ReverseList(head);
    if(newHead==NULL)
        return 0;
    cout<<newHead->val<<endl;
    while(newHead->next != NULL)
    {
        newHead = newHead->next;
        cout<<newHead->val<<endl;
    }
    return 0;
}
