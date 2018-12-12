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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = ListLength(pHead1);
        int len2 = ListLength(pHead2);
        if(len1>len2)
            pHead1 = walkList(pHead1, len1-len2);
        else
            pHead2 = walkList(pHead2, len2-len1);
        while(pHead1!=pHead2)
        {
            pHead1 = pHead1->next;
            pHead2 = pHead2->next;
        }
        return pHead1;
    }
    int ListLength(ListNode* pHead)
    {
        int length = 0;
        if(pHead==NULL) return 0;
        ++length;
        while(pHead=pHead->next)
            ++length;
        return length;
    }
    ListNode* walkList(ListNode* pHead, int step)
    {
        while(step--)
            pHead = pHead->next;
        return pHead;
    }

};

int main()
{
    return 0;
}
