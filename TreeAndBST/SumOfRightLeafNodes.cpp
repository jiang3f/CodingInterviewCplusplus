//
// https://practice.geeksforgeeks.org/problems/sum-of-right-leaf-nodes/1/
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

namespace SumOfRightLeafNodes
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

	void inorder(Node* root)
	{
		if (root == NULL)return;
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}

    int rightLeavesSumSub(Node* node, bool isright)
    {
        if (node == nullptr)    return 0;
        if (node->left == nullptr && node->right == nullptr && isright == true)  return node->data;

        int ret = rightLeavesSumSub(node->left, false);
        ret += rightLeavesSumSub(node->right, true);

        return ret;
    }


    int rightLeafSum(Node* root)
    {
        if (root == nullptr)    return 0;

        return rightLeavesSumSub(root, false);
    }

};

int SumOfRightLeafNodes_Test ()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        map<int, SumOfRightLeafNodes::Node*> m;
        int n;
        scanf("%d", &n);
        struct SumOfRightLeafNodes::Node* root = NULL;
        struct SumOfRightLeafNodes::Node* child;
        while (n--)
        {
            SumOfRightLeafNodes::Node* parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new SumOfRightLeafNodes::Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new SumOfRightLeafNodes::Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        // inorder(root);
        // cout<<endl;
        cout << SumOfRightLeafNodes::rightLeafSum(root) << endl;
    }
    return 0;
}