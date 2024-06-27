#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;

    ListNode *CreateLinkedList(int elementOfLL[], int sizeOfArray)
    {
        ListNode *head, *tempNode, *it;

        head = new ListNode;
        head->val = elementOfLL[0];
        head->next = NULL;
        it = head;

        for (int i = 1; i < sizeOfArray; i++)
        {
            tempNode = new ListNode;
            tempNode->val = elementOfLL[i];
            tempNode->next = NULL;
            it->next = tempNode;
            it = tempNode;
        }

        return head;
    }

    void DisplayElement(ListNode *head)
    {
        while (head)
        {
            cout << " |" << head->val << "|| ";
            head = head->next;
        }

        cout << endl;
    }
};

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        ListNode *tempNode, *p;
        tempNode = head;

        while (tempNode->next && tempNode->next->next)
        {
            p = tempNode;
            while (p->next->next)
                p = p->next;

            p->next->next = tempNode->next;
            tempNode->next = p->next;
            tempNode = p->next->next;
            p->next = NULL;
        }
    }
};

int main()
{
    Solution s;
    ListNode l;
    ListNode *head;
    int elementOfLL[] = {1, 2, 3, 4, 5}; // 1 -> 5 -> 2 -> 4 -> 3
    int n = sizeof(elementOfLL) / sizeof(elementOfLL[0]);
    head = l.CreateLinkedList(elementOfLL, n);
    l.DisplayElement(head);
    s.reorderList(head);
    l.DisplayElement(head);
}