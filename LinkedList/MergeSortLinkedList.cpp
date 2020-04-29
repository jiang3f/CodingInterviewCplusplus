
//
// https://practice.geeksforgeeks.org/problems/sort-a-linked-list/1
//
// { Driver Code Starts

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct Node {
	int data;
	struct Node* next;
	Node(int x) {
		data = x;
		next = NULL;
	}
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node
{
int data;
struct Node* next;
Node(int x) { data = x;  next = NULL; }
};
*/
void push(struct Node** head_ref, int new_data);

Node * merge(Node * left, Node *right)
{
	Node *leftCur = left;
	Node *rightCur = right;
	Node * out = NULL;
	Node * cur = NULL;
	while (leftCur != NULL && rightCur != NULL)
	{
		int data;
		if (leftCur->data < rightCur->data)
		{
			data = leftCur->data;
			leftCur = leftCur->next;
		}
		else
		{
			data = rightCur->data;
			rightCur = rightCur->next;
		}
		if (out == NULL)
		{
			out = new Node(data);
			cur = out;
		}
		else
		{
			cur->next = new Node(data);
			cur = cur->next;
		}
	}
	while (leftCur != NULL)
	{
		cur->next = new Node(leftCur->data);
		cur = cur->next;
		leftCur = leftCur->next;

	}
	while (rightCur != NULL)
	{
		cur->next = new Node(rightCur->data);
		cur = cur->next;
		rightCur = rightCur->next;
	}

	return out;
}

/* Function to mergesort the linked list
It should return head of the modified list  */
Node* mergeSort(Node* head) {
	// your code here
	int n = 0;
	Node * cur = head;
	Node * out = NULL;
	while (cur != nullptr)
	{
		n++;
		cur = cur->next;
	}
	if (n < 2)
	{
		push(&out, head->data);
		return out;
	}

	Node * left = NULL;
	cur = head;
	for (int i = 0; i < n / 2; i++)
	{
		push(&left, cur->data);
		cur = cur->next;
	}
	Node *right = NULL;
	while (cur != NULL)
	{
		push(&right, cur->data);
		cur = cur->next;
	}
	Node *l = mergeSort(left);
	Node *r = mergeSort(right);

	out = merge(l, r);

	// free left
	// free right

}


// { Driver Code Starts.

void printList(Node* node) {
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
	printf("\n");
}

void push(struct Node** head_ref, int new_data) {
	Node* new_node = new Node(new_data);

	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}


//
// 1 
// 5
// 3 5 2 4 1
int MergeSortLinkedList_Test() 
{
	long test;
	cin >> test;
	while (test--) {
		struct Node* a = NULL;
		long n, tmp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> tmp;
			push(&a, tmp);
		}
		a = mergeSort(a);
		printList(a);
	}
	return 0;
}  // } Driver Code Ends

