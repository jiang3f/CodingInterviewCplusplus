//
// https://practice.geeksforgeeks.org/problems/delete-without-head-pointer/1
/*
*
Expected Time Complexity : O(1)
Expected Auxilliary Space : O(1)

Constraints:
1 <= N <= 103

*/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace DeleteWithoutHeadPointer
{

    /* Link list node */
    struct Node {
        int data;
        struct Node* next;
        Node(int x) {
            data = x;
            next = NULL;
        }
    }*head;

    Node* findNode(Node* head, int search_for)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->data == search_for)
                break;
            current = current->next;
        }
        return current;
    }


    void insert()
    {
        int n, i, value;
        Node* temp=nullptr;
        scanf("%d", &n);

        for (i = 0; i < n; i++)
        {
            scanf("%d", &value);
            if (i == 0)
            {
                head = new Node(value);
                temp = head;
                continue;
            }
            else
            {
                temp->next = new Node(value);
                temp = temp->next;
                temp->next = NULL;
            }
        }
    }

    /* Function to print linked list */
    void printList(Node* node)
    {
        while (node != NULL)
        {
            printf("%d ", node->data);
            node = node->next;
        }
        cout << endl;
    }


    // This function should delete node from linked list. The function
    // may assume that node exists in linked list and is not last node
    // node: reference to the node which is to be deleted
    void deleteNode(Node* node)
    {
        // Your code here

        if (node == head)
        {
            head = head->next;
            delete node;
        }
        else
        {
            Node* tmp = node->next;
            node->data = tmp->data;
            node->next = tmp->next;
            delete tmp;
        }

    }



};

// Driven Program 
// 
int DeleteWithoutHeadPointer_Test()
{
    /* Start with the empty list */

    int t, k, n, value;

    scanf("%d", &t);
    while (t--)
    {
        DeleteWithoutHeadPointer::insert();
        scanf("%d", &k);
        DeleteWithoutHeadPointer::Node* del = DeleteWithoutHeadPointer::findNode(DeleteWithoutHeadPointer::head, k);
        if (del != NULL && del->next != NULL)
        {
            DeleteWithoutHeadPointer::deleteNode(del);
        }
        DeleteWithoutHeadPointer::printList(DeleteWithoutHeadPointer::head);
    }
    return(0);
}