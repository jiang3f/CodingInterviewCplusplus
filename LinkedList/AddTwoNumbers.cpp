/*
* https://leetcode.com/problems/add-two-numbers/
*/

/*
* 
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/
#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;
namespace AddTwoNumbers
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

    class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode* ret = nullptr;

            if (l1 == nullptr && l2 == nullptr)
            {
                ret = new ListNode();
                return ret;
            }

            int up = 0;
            stack<int> s;

            while (l1 != nullptr && l2 != nullptr)
            {
                //cout << "l1= " << l1->val << " l2= " << l2->val << " ";
                //int v = l1->val + l2->val;
                //v += up;
                //cout << "l1 + l2 + up = " << v << " ";

                s.push((l1->val + l2->val + up) % 10);
                up = (l1->val + l2->val + up) / 10;
                l1 = l1->next;
                l2 = l2->next;
            }

            while (l1 != nullptr)
            {
                s.push((l1->val + up) % 10);
                up = (l1->val + up) / 10;
                l1 = l1->next;
            }

            while (l2 != nullptr)
            {
                s.push((l2->val + up) % 10);
                up = (l2->val + up) / 10;
                l2 = l2->next;
            }

            if (up > 0) s.push(up);

            //cout << endl;

            while (s.empty() == false)
            {
                int v = s.top();
                s.pop();

                if (ret == nullptr)
                {
                    ret = new ListNode(v);
                }
                else
                {
                    ret = new ListNode(v, ret);
                }
            }
            return ret;
        }
    };
}

int AddTwoNumbers_Test()
{
    int a1[] = { 9, 9, 9, 9, 9, 9, 9 };
    int a2[] = { 9, 9, 9, 9 };

    AddTwoNumbers::ListNode* l1 = AddTwoNumbers::MakeList(a1, sizeof(a1)/sizeof(a1[0]));
    AddTwoNumbers::ListNode* l2 = AddTwoNumbers::MakeList(a2, sizeof(a2) / sizeof(a2[0]));

    AddTwoNumbers::Solution ob;
    AddTwoNumbers::ListNode* ret = ob.addTwoNumbers(l1, l2);
    return 0;
}
