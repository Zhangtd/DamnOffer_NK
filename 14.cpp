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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
    int length = 0;
    ListNode *res = pListHead;
    if(res==NULL)
        return NULL;
    if(res!= NULL)
    {
        length++;
        while(res->next != NULL)
        {
            length++;
            res = res->next;
        }
    }
    if(length<k)
        return NULL;
    res = pListHead;
    for(int i=0; i< length-k; i++)
    {
        res = res->next;
    }
    return res;
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
    Solution solution;
    cout<<solution.FindKthToTail(head, 1)->val;
    return 0;
}
