
//
// https://www.geeksforgeeks.org/lru-cache-implementation/
//
// { Driver Code Starts

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <list>
#include <map>

using namespace std;

#define MAX_FRAMES 3

namespace LruCachePageFault
{
	struct Node {
		int data;
		struct Node* next;
		struct Node* pre;

		Node(int x) {
			data = x;
			next = NULL;
			pre = NULL;
		}
	};


	struct Node *FindNote(struct Node * head, int v)
	{
		while (head != nullptr)
		{
			if (head->data == v)	return head;

			head = head->next;
		}

		return nullptr;
	}


	void printList(Node* node) {
		while (node != NULL) {
			printf("%d ", node->data);
			node = node->next;
		}
		printf("\n");
	}


	void Run(int arr[], int len)
	{
		struct Node *head = nullptr;
		struct Node *tail = nullptr;
		int frames = 0;

		for (int i = 0; i < len; i++)
		{
			struct Node *hitElem = FindNote(head, arr[i]);

			if (hitElem == nullptr)
			{
				hitElem = new struct Node(arr[i]);

				if (head == nullptr)
				{
					head = hitElem;
					tail = hitElem;
					frames = 1;
				}
				else
				{
					hitElem->next = head;
					head->pre = hitElem;
					head = hitElem;
					frames++;

					if (frames > MAX_FRAMES)
					{
						struct Node * tmp = tail->pre;

						if (tmp == nullptr)
						{
							cout << "error";
						}
						delete tail;
						tail = tmp;
						tail->next = nullptr;
						frames--;
					}
				}
			}
			else
			{
				if (head != hitElem)
				{
					struct Node *tmp = hitElem->pre;

					if (hitElem == tail)
					{
						tmp->next = nullptr;
						tail = tmp;
					}
					else
					{
						tmp->next = hitElem->next;
						tmp->next->pre = tmp;
					}

					hitElem->pre = nullptr;
					hitElem->next = head;
					head->pre = hitElem;
					head = hitElem;
				}
			}

			// print list

			if (head == nullptr || tail == nullptr)
			{
				cout << "error" << endl;
			}
			printList(head);



		}
	}

	class LRUCache
	{
		// store keys of cache 
		list<int> dq;

		// store references of key in cache 
		map<int, list<int>::iterator> ma;
		int csize; // maximum capacity of cache 

	public:
		LRUCache(int);
		void refer(int);
		void display();

	};

	// Declare the size 
	LRUCache::LRUCache(int n)
	{
		csize = n;
	}

	// Refers key x with in the LRU cache 
	void LRUCache::refer(int x)
	{
		// not present in cache 
		if (ma.find(x) == ma.end()) {
			// cache is full 
			if (dq.size() == csize) {
				// delete least recently used element 
				int last = dq.back();

				// Pops the last elmeent 
				dq.pop_back();

				// Erase the last 
				ma.erase(last);
			}
		}

		// present in cache 
		else
			dq.erase(ma[x]);

		// update reference 
		dq.push_front(x);
		ma[x] = dq.begin();

		display();
	}

	// Function to display contents of cache 
	void LRUCache::display()
	{

		// Iterate in the deque and print 
		// all the elements in it 
		for (auto it = dq.begin(); it != dq.end();
			it++)
			cout << (*it) << " ";

		cout << endl;
	}

	void Run1(int arr[], int len)
	{
		LRUCache ca(MAX_FRAMES);

		for (int i = 0; i < len; i++)
		{
			ca.refer(arr[i]);
		}

		ca.display();
	}
};

//
// 1 
// 12
// 1 2 3 4 1 2 5 1 2 3 4 5
int LruCachePageFault_Test()
{
	int test;
	cin >> test;
	while (test--) {
		int n;
		cin >> n;
		int* arr = new int[n];
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		LruCachePageFault::Run(arr, n);

		cout << "Their solution: " << endl;

		LruCachePageFault::Run1(arr, n);
	}
	return 0;
}  // } Driver Code Ends

