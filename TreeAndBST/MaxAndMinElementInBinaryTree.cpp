//
// https://practice.geeksforgeeks.org/problems/max-and-min-element-in-binary-tree/1/
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

namespace MaxAndMinElementInBinaryTree
{

    // A tree node
    struct node
    {
        int data;
        struct node* left;
        struct node* right;

        node(int x) {
            data = x;
            left = NULL;
            right = NULL;
        }
    };

    void insert(struct node* root, int n1, int n2, char lr)
    {
        if (root == NULL)
            return;
        if (root->data == n1)
        {
            switch (lr)
            {
            case 'L': root->left = new node(n2);
                break;
            case 'R': root->right = new node(n2);
                break;
            }
        }
        else
        {
            insert(root->left, n1, n2, lr);
            insert(root->right, n1, n2, lr);
        }
    }

    // Returns maximum value in a given Binary Tree
    int findMax(struct node* root)
    {
        int max = INT_MIN;

        if (root == nullptr)    return max;

        queue<node*> q;
        q.push(root);

        while (q.size() != 0)
        {
            node* cur = q.front();
            q.pop();

            if (cur->data > max)
            {
                max = cur->data;
            }

            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
        return max;
    }
    
    // Returns minimum value in a given Binary Tree
    int findMin(struct node* root)
    {
        int min = INT_MAX;

        if (root == nullptr)    return min;

        queue<node*> q;
        q.push(root);

        while (q.size() != 0)
        {
            node* cur = q.front();
            q.pop();

            if (cur->data < min)
            {
                min = cur->data;
            }

            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
        }
        return min;
    }
};

int MaxAndMinElementInBinaryTree_Test ()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        struct MaxAndMinElementInBinaryTree::node* root = NULL;
        while (n--)
        {
            char lr;
            int n1, n2;
            cin >> n1 >> n2;
            cin >> lr;
            if (root == NULL)
            {
                root = new MaxAndMinElementInBinaryTree::node(n1);
                switch (lr) {
                case 'L': root->left = new MaxAndMinElementInBinaryTree::node(n2);
                    break;
                case 'R': root->right = new MaxAndMinElementInBinaryTree::node(n2);
                    break;
                }
            }
            else
            {
                MaxAndMinElementInBinaryTree::insert(root, n1, n2, lr);
            }
        }

        cout << MaxAndMinElementInBinaryTree::findMax(root) << " " << MaxAndMinElementInBinaryTree::findMin(root) << endl;
    }

    return 0;
}
