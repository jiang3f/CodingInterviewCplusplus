/*
* https://leetcode.com/problems/reverse-nodes-in-k-group/
*/

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

namespace ReverseNodesInkGroup
{
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */
     /**
      * Definition for singly-linked list.
      * struct ListNode {
      *     int val;
      *     ListNode *next;
      *     ListNode() : val(0), next(nullptr) {}
      *     ListNode(int x) : val(x), next(nullptr) {}
      *     ListNode(int x, ListNode *next) : val(x), next(next) {}
      * };
      */
    struct ListNode
    {
        int val;
        ListNode* next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode* next) : val(x), next(next) {}
    };

    ListNode* MakeList(int arr[], int n)
    {
        ListNode* ret = nullptr;

        for (int i = n - 1; i >= 0; i--)
        {
            if (ret == nullptr)
            {
                ret = new ListNode(arr[i]);
            }
            else
            {
                ret = new ListNode(arr[i], ret);
            }
        }
        return ret;
    }

    void PrintNode(ListNode* ret)
    {
        cout << "{";

        while (ret != NULL)
        {
            cout << ret->val << ", ";
            ret = ret->next;
        }
        cout << "}" << endl;
    }

    class Solution {
    public:
        ListNode* StackAdd(int k, stack<ListNode*>& s, ListNode* head)
        {
            ListNode* last = NULL;

            int i = 0;
            for (i = 0; i < k; i++)
            {
                if (head == NULL)   break;
                last = head->next;
                s.push(head);
                head = head->next;
            }

            return last;
        }

        ListNode* MakeReverseList(ListNode** last, stack<ListNode*>& s, bool isReverse)
        {
            ListNode* head = NULL;
            ListNode* tail = NULL;

            while (!s.empty())
            {
                ListNode* node = s.top();
                s.pop();

                if (!isReverse)
                {
                    node->next = NULL;

                    if (tail == NULL)
                    {
                        tail = node;
                    }
                    node->next = head;
                    head = node;
                }
                else
                {
                    if (head == NULL)
                    {
                        head = node;
                        tail = head;
                    }
                    else
                    {
                        tail->next = node;
                        tail = node;
                    }
                    tail->next = NULL;
                }
            }

            if (*last == NULL)
            {
                *last = head;
            }
            else
            {
                (*last)->next = head;
            }
            return tail;
        }

        ListNode* reverseKGroup(ListNode* head, int k)
        {
            ListNode* ret = NULL;
            ListNode* last = ret;
            stack<ListNode*> s;

            while (head != NULL)
            {
                head = StackAdd(k, s, head);

                if (s.size() < k)
                {
                    if (ret == NULL)
                    {
                        last = MakeReverseList(&ret, s, false);
                    }
                    else
                    {
                        last = MakeReverseList(&last, s, false);
                    }
                }
                else
                {
                    if (ret == NULL)
                    {
                        last = MakeReverseList(&ret, s, true);
                    }
                    else
                    {
                        last = MakeReverseList(&last, s, true);
                    }
                }
            }

            return ret;
        }
    };
};

int ReverseNodesInkGroup_Test()
{
    int a1[] = { 1,2,3,4,5 };

    ReverseNodesInkGroup::ListNode* l1 = ReverseNodesInkGroup::MakeList(a1, sizeof(a1) / sizeof(a1[0]));

    int k = 2;

    ReverseNodesInkGroup::Solution ob;

    ReverseNodesInkGroup::ListNode* ret = ob.reverseKGroup(l1, k);

    ReverseNodesInkGroup::PrintNode(ret);

    return 0;

}
