//
// https://www.geeksforgeeks.org/modify-binary-tree-get-preorder-traversal-using-right-pointers/
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

using namespace std;

namespace PreorderTravesalBTree
{

	// left child and right child 
	struct Node {
		int data;
		struct Node* left;
		struct Node* right;
	};

	// function that allocates a new node 
	// with the given data and NULL left 
	// and right pointers. 
	struct Node* newNode(int data)
	{
		struct Node* node = new struct Node;
		node->data = data;
		node->left = NULL;
		node->right = NULL;
		return (node);
	}

	//
	// My method
	//
	struct Node* modifytree_mine(struct Node * root)
	{
		if (root == nullptr)
		{
			return nullptr;
		}

		struct Node * head = modifytree_mine(root->left);

		if (head != nullptr)
		{
			struct Node *cur = head;
			while (cur->right != nullptr)	cur = cur->right;
			cur->right = modifytree_mine(root->right);
		}
		else
		{
			head = modifytree_mine(root->right);
		}

		root->right = head;
		root->left = nullptr;

		return root;
	}

	//
	// Method 1 (Recursive) 
	//

	// Function to modify tree
	struct Node* modifytree_method_1(struct Node* root)
	{
		struct Node* right = root->right;
		struct Node* rightMost = root;

		// if the left tree exists 
		if (root->left) {

			// get the right-most of the 
			// original left subtree 
			rightMost = modifytree_method_1(root->left);

			// set root right to left subtree 
			root->right = root->left;
			root->left = NULL;
		}

		// if the right subtree does 
		// not exists we are done! 
		if (!right)
			return rightMost;

		// set right pointer of right-most 
		// of the original left subtree 
		rightMost->right = right;

		// modify the rightsubtree 
		rightMost = modifytree_method_1(right);
		return rightMost;
	}

	//
	// Method 2 (Iterative)
	//
	// Time Complexity: O(N)
	// Auxiliary Space : O(N), where N is the total number of nodes in the tree.
	//
	struct Node* modifytree_method_2(struct Node* root)
	{
		stack<struct Node> nodeStack;

		nodeStack.push(*root);

		while (!nodeStack.empty())
		{
			struct Node item = nodeStack.top();
			cout << item.data << " ";
			nodeStack.pop();
			if ((item).right != nullptr)		nodeStack.push(*(item.right));
			if ((item).left != nullptr)		nodeStack.push(*(item.left));
		}

		return nullptr;
	}


	// printing using right pointer only 
	void printpre(struct Node* root)
	{
		while (root != NULL) {
			cout << root->data << " ";
			root = root->right;
		}
	}

	/* Constructed binary tree is
	10
	/ \
	8   2
	/ \
	3   5
	*/
	int Run()
	{
		struct Node* root = newNode(10);
		root->left = newNode(8);
		root->right = newNode(2);
		root->left->left = newNode(3);
		root->left->right = newNode(5);

		cout << "modifytree_mine: " << endl;
		modifytree_mine(root);
		printpre(root);
		cout << endl;

		cout << "modifytree_method_1: " << endl;
		modifytree_method_1(root);
		printpre(root);
		cout << endl;

		cout << "modifytree_method_2: " << endl;
		modifytree_method_2(root);
		cout << endl;

		return 0;
	}  // } Driver Code Ends

};

int PreorderTravesalBTree_Test()
{
	PreorderTravesalBTree::Run();

	return 0;
}

