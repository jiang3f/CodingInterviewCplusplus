/*
* https://iq.opengenus.org/persistent-segment-tree/
* https://www.geeksforgeeks.org/persistent-segment-tree-set-1-introduction/

Given an array A[] and different point update operations.

Considering each point operation to create a new version of the array. We need to answer the queries of type:

Q v l r : output the sum of elements in range l to r just after the v-th update.

*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace PersistentSegmentTree
{
	const int MAX = 100;

	struct node
	{
		int val;

		node* left, * right;

		// Constructor

		node() {}

		node(node* l, node* r, int v)
		{
			left = l;
			right = r;
			val = v;
		}
	};


	// input array 
	int arr[MAX];

	//array storing root pointers for all versions 
	node* version[MAX];

	class Solution
	{
	public:
		void build(node* root, int low, int high)
		{
			if (low == high)
			{
				root->val = arr[low];
				return;
			}

			int mid = (low + high) / 2;

			root->left = new node(NULL, NULL, 0);

			build(root->left, low, mid);

			root->right = new node(NULL, NULL, 0);

			build(root->right, mid + 1, high);

			root->val = root->left->val + root->right->val;

			return;
		}

		void upgrade(node* oldversion, node* newversion, int low, int high, int index, int value)
		{
			if (index < low || index > high)
			{
				newversion->val = oldversion->val;

				newversion->left = oldversion->left;

				newversion->right = oldversion->right;

				return;
			}

			if (low == high)
			{
				newversion->val = value;
				
				return;
			}

			int mid = (low + high) / 2;

			if (index <= mid)
			{
				newversion->right = oldversion->right;

				newversion->left = new node(NULL, NULL, 0);

				upgrade(oldversion->left, newversion->left, low, mid, index, value);

			}
			else
			{
				newversion->left = oldversion->left;

				newversion->right = new node(NULL, NULL, 0);

				upgrade(oldversion->right, newversion->right, mid + 1, high, index, value);
			}

			newversion->val = newversion->left->val + newversion->right->val;
		}

		int query(node* version, int low, int high, int qlow, int qhigh)
		{
			if (low > qhigh || high < qlow)
			{
				return 0;
			}

			if (low >= qlow && high <= qhigh)
			{
				return version->val;
			}

			int mid = (low + high) / 2;

			return query(version->left, low, mid, qlow, qhigh) + query(version->right, mid + 1, high, qlow, qhigh);

		}
	};
};

int PersistentSegmentTree_Test()
{
	int A[] = { 5,6,7,8 };
	int n = sizeof(A) / sizeof(int);

	for (int i = 0; i < n; i++)
		PersistentSegmentTree::arr[i] = A[i];

	// Version-0 
	PersistentSegmentTree::node* root = new PersistentSegmentTree::node(NULL, NULL, 0);
	
	PersistentSegmentTree::Solution ob;

	ob.build(root, 0, n - 1);

	// storing root node for version-0 
	PersistentSegmentTree::version[0] = root;

	//Creating Version-1 root by initialising it by '0'
	PersistentSegmentTree::version[1] = new PersistentSegmentTree::node(NULL, NULL, 0);
	
	//Upgrading Version-1
	ob.upgrade(PersistentSegmentTree::version[0], PersistentSegmentTree::version[1], 0, n - 1, 0, 1);

	//Creating Version-2 root by initialising it by '0'
	PersistentSegmentTree::version[2] = new PersistentSegmentTree::node(NULL, NULL, 0);
	//Upgrading Version-2
	ob.upgrade(PersistentSegmentTree::version[1], PersistentSegmentTree::version[2], 0, n - 1, 3, 10);

	cout << "Version-0 , query(0,2) : ";
	cout << ob.query(PersistentSegmentTree::version[0], 0, n - 1, 0, 2) << endl;

	cout << "Version-1 , query(0,2) : ";
	cout << ob.query(PersistentSegmentTree::version[1], 0, n - 1, 0, 2) << endl;

	cout << "Version-2 , query(0,2) : ";
	cout << ob.query(PersistentSegmentTree::version[2], 0, n - 1, 0, 2) << endl;

	return 0;
}
