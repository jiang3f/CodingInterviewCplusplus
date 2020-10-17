//
// https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>      // std::istringstream
#include <map>
#include <deque>


using namespace std;

namespace SumOfBinaryTree
{
	struct Node
	{
		int key;
		struct Node* left;
		struct Node* right;

		Node(int x) {
			key = x;
			left = NULL;
			right = NULL;
		}
	};

	Node* make_tree()
	{
		int n;
		cin >> n;

		Node* head = NULL;
		queue <Node*> q;

		for (; n > 0; n -= 2)
		{
			int a, b;
			char c;
			cin >> a >> b >> c;

			if (!head)
			{
				head = new Node(a);
				q.push(head);
			}

			Node* pick = q.front();
			q.pop();

			if (c == 'L')
			{
				pick->left = new Node(b);
				q.push(pick->left);
			}


			cin >> a >> b >> c;

			if (c == 'R')
			{
				pick->right = new Node(b);
				q.push(pick->right);
			}
		}
		return head;
	}

	long int sumBT(Node* root)
	{
		if (root == nullptr)	return 0;

		long ret = sumBT(root->left);

		ret += sumBT(root->right);

		ret += root->key;

		return ret;
	}

};

int SumOfBinaryTree_Test ()
{
	int t; cin >> t; while (t--) {

		SumOfBinaryTree::Node* head = SumOfBinaryTree::make_tree();

		cout << SumOfBinaryTree::sumBT(head) << endl;
	}
	return 1;
}