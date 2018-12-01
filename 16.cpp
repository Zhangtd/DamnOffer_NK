#include<iostream>
#include<algorithm>
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
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if(pHead1==NULL)
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        ListNode *node = NULL;
        if(pHead1->val < pHead2->val)
        {
            node = pHead1;
            node->next = Merge(pHead1->next, pHead2);
        }
        else
        {
            node = pHead2;
            node->next = Merge(pHead1, pHead2->next);
        }
        return node;
    }

};
int main()
{
    ListNode *list1 = new ListNode(1);
    ListNode *list2 = new ListNode(0);
    ListNode *node1 = list1;
    ListNode *node2 = list2;
    for(int i=2; i<=10; i++)
    {
        ListNode *node = new ListNode(i);
        if(i%2==0)
        {
            node1->next = node;
            node1 = node;
        }
        else
        {
            node2->next = node;
            node2 = node;
        }
    }
//    ListNode *head;
//    head = list2;
//    cout<<head->val<<" ";
//    while(head->next != NULL)
//    {
//        head = head->next;
//        cout<<head->val<<" ";
//    }
//    cout<<endl;
    Solution solution;
    ListNode *res;
    res = solution.Merge(list1, list2);
    cout<<res->val<<" ";
    while(res->next != NULL)
    {
        res = res->next;
        cout<<res->val<<" ";
    }
    cout<<endl;
    return 0;
}
