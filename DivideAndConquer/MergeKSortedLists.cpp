/*
* https://leetcode.com/problems/merge-k-sorted-lists/description/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace MergeKSortedLists
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
        struct CustomCompare
        {
            bool operator()(const ListNode& lhs, const ListNode& rhs)
            {
                return lhs.val > rhs.val;
            }
        };

        ListNode* mergeKLists(vector<ListNode*>& lists) 
        {

            priority_queue<ListNode, vector<ListNode>, CustomCompare > pq;

            for (int i = 0; i < lists.size(); i++)
            {
                ListNode* node = lists[i];

                if (node != NULL)                pq.push(*node);
            }

            ListNode* last = NULL;
            ListNode* ret = NULL;

            while (!pq.empty())
            {
                ListNode node = pq.top();

                pq.pop();

                if (last == NULL)
                {
                    last = new ListNode(node.val);
                    ret = last;
                }
                else
                {
                    last->next = new ListNode(node.val);
                    last = last->next;
                }
                if (node.next != NULL)            pq.push(*(node.next));
            }

            return ret;
        }
    };
}

int MergeKSortedLists_Test()
{
    /*int a1[] = { 1,4,5 };
    int a2[] = { 1,3,4 };
    int a3[] = { 2, 6 };

    vector<MergeKSortedLists::ListNode*> v;

    MergeKSortedLists::ListNode* l1 = MergeKSortedLists::MakeList(a1, sizeof(a1) / sizeof(a1[0]));
    MergeKSortedLists::ListNode* l2 = MergeKSortedLists::MakeList(a2, sizeof(a2) / sizeof(a2[0]));
    MergeKSortedLists::ListNode* l3 = MergeKSortedLists::MakeList(a3, sizeof(a3) / sizeof(a3[0]));

    v.push_back(l1);
    v.push_back(l2);
    v.push_back(l3);
    */

    vector<MergeKSortedLists::ListNode*> v;

    MergeKSortedLists::ListNode* l1 = NULL;

    v.push_back(l1);

    MergeKSortedLists::Solution ob;

    MergeKSortedLists::ListNode * ret = ob.mergeKLists(v);

    MergeKSortedLists::PrintNode(ret);

    return 0;
}
