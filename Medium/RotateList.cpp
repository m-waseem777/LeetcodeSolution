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
    ListNode *rotateRight(ListNode *head, int k)
    {
        ListNode *tempNode;

        if (!head || !head->next)
            return head;

        int lengthOfLL = LengthOfLL(head);
        k = k % lengthOfLL;

        while (k--)
        {
            tempNode = head;
            while (tempNode->next->next)
                tempNode = tempNode->next;

            tempNode->next->next = head;
            head = tempNode->next;
            tempNode->next = nullptr;
        }

        return head;
    }

    int LengthOfLL(ListNode *head)
    {
        int len = 0;
        while (head)
        {
            len++;
            head = head->next;
        }

        return len;
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
    head = s.rotateRight(head, 50000000);
    l.DisplayElement(head);
}