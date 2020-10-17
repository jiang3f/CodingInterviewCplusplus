//
// https://practice.geeksforgeeks.org/problems/preorder-traversal/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>      // std::istringstream
#include <map>
#include <stack>


using namespace std;

namespace CountNonLeafNodesInTree
{
	struct Node
	{
		int data;
		struct Node* left;
		struct Node* right;

		Node(int x) {
			data = x;
			left = NULL;
			right = NULL;
		}
	};

	int countNonLeafNodes(Node* root)
	{
        if (root == nullptr)    return 0;

        int ret = 0;

        if (root->left != nullptr || root->right != nullptr)
        {
            ret = 1;

            ret += countNonLeafNodes(root->left);

            ret += countNonLeafNodes(root->right);
        }

		return ret;
	}

};

int CountNonLeafNodesInTree_Test()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        map<int, CountNonLeafNodesInTree::Node*> m;
        int n;
        scanf("%d", &n);
        struct CountNonLeafNodesInTree::Node* root = NULL;
        struct CountNonLeafNodesInTree::Node* child;
        while (n--)
        {
            CountNonLeafNodesInTree::Node* parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new CountNonLeafNodesInTree::Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new CountNonLeafNodesInTree::Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        cout << CountNonLeafNodesInTree::countNonLeafNodes(root) << endl;
    }
    return 0;
}