#include<iostream>
using namespace std;


struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone1(RandomListNode* pHead)
    {
        if(pHead==NULL) return NULL;
        RandomListNode *nHead = new RandomListNode(pHead->label);
        RandomListNode *node = nHead;
        RandomListNode *node_p = pHead->next;
        RandomListNode *p[1000];
        int i=0;
        p[i++] = pHead->random;

        while(node_p!=NULL)
        {
            RandomListNode *tmp = new RandomListNode(node_p->label);
            node->next = tmp;
            p[i++] = node_p->random;
            node_p = node_p->next;
            node = node->next;
        }
        node = nHead;
        for(int j=0; j<i; j++)
        {
            node->random = p[j];
            node = node->next;
        }
        return nHead;
    }

    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead==NULL)
            return NULL;
        RandomListNode* curNode=pHead;
        while(curNode!=NULL)
        {
            RandomListNode* newNode = new RandomListNode(curNode->label);
            newNode->next = curNode->next;
            curNode->next = newNode;
            curNode = curNode->next->next;
        }
        curNode = pHead;
        while(curNode!=NULL)
        {
            RandomListNode* node = curNode->next;
            if(curNode->random!=NULL)
                node->random = curNode->random->next;
            curNode = curNode->next->next;
        }

        RandomListNode* nHead=pHead->next;
        RandomListNode* tmp;
        curNode = pHead;
        while(curNode->next!=NULL)
        {
            tmp = curNode->next;
            curNode->next = tmp->next;
            curNode = tmp;
        }
        return nHead;
    }
};

void randomVisit(RandomListNode *head)
{
    RandomListNode *node = head;
    while(node!=NULL)
    {
        cout<<node->label<<" "<<node->random->label<<endl;
        node = node->next;
    }
    cout<<endl;
}

int main()
{
    int a[]={1,2,3,4,5,6};
    RandomListNode *head = new RandomListNode(a[0]);
    RandomListNode *node = head;
    for(int i=1; i<6; i++)
    {
        RandomListNode *tmp = new RandomListNode(a[i]);
        node->next = tmp;
        tmp->random = node;
        node = node->next;
    }
    head->random = node;
    randomVisit(head);

    Solution solution;
    RandomListNode *nHead = solution.Clone(head);
    randomVisit(nHead);
    return 0;
}
