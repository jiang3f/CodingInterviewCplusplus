//
// https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes-in-bst/1/
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

namespace SumOfLeafNodesInBST
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

    Node* insert(Node* r, int num) {
        if (r == NULL) {
            r = new Node(num);
        }
        else {
            if (num < r->data) {
                r->left = insert(r->left, num);
            }
            else {
                r->right = insert(r->right, num);
            }
        }
        return r;
    }

    void preOrderDisplay(Node* r) {
        if (r != NULL) {
            printf("%d ", r->data);
            preOrderDisplay(r->left);
            preOrderDisplay(r->right);
        }
    }

    void inOrderDisplay(Node* r) {
        if (r != NULL) {
            inOrderDisplay(r->left);
            printf("%d ", r->data);
            inOrderDisplay(r->right);
        }
    }

    void postOrderDisplay(Node* r) {
        if (r != NULL) {
            postOrderDisplay(r->left);
            postOrderDisplay(r->right);
            printf("%d ", r->data);
        }
    }

    int search(Node* r, int num) {
        if (r == NULL)return 0;
        else if (r->data == num)return 0;
        else if (r->data > num)
            search(r->left, num);
        else
            search(r->right, num);
    }// } Driver Code Ends

/*You are required to complete below method */
    int sumOfLeafNodes(Node* r)
    {
        if (r == nullptr)   return 0;

        int ret = 0;

        if (r->left == nullptr && r->right == nullptr)
        {
            return r->data;
        }
        if (r->left != nullptr)
        {
            ret += sumOfLeafNodes(r->left);
        }
        if (r->right != nullptr)
        {
            ret += sumOfLeafNodes(r->right);
        }

        return ret;
    }
};

int SumOfLeafNodesInBST_Test ()
{
    int t, n, data;
    scanf("%d", &t);
    while (t--) {
        SumOfLeafNodesInBST::Node* root = NULL;
        scanf("%d", &n);
        //printf("n=%d\n",n);
        while (n--) {
            scanf("%d", &data);
            //printf("data=%d\n",data);
            root = SumOfLeafNodesInBST::insert(root, data);
        }
        //inOrderDisplay(root);
        printf("%d\n", SumOfLeafNodesInBST::sumOfLeafNodes(root));
    }
    return 0;
}
