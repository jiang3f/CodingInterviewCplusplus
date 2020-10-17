//
// https://practice.geeksforgeeks.org/problems/sum-of-leaf-nodes/1/
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

namespace SumOfLeafNodes
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

    int sumLeaf(Node* root)
    {
        if (root == nullptr)    return 0;

        if (root->left == nullptr && root->right == nullptr)
        {
            return root->data;
        }

        int ret = sumLeaf(root->left);
        ret += sumLeaf(root->right);
       
        return ret;
    }
};

int SumOfLeafNodes_Test ()
{
    int t;
    struct SumOfLeafNodes::Node* child;
    scanf("%d", &t);
    while (t--)
    {
        map<int, SumOfLeafNodes::Node*> m;
        int n;
        scanf("%d", &n);
        struct SumOfLeafNodes::Node* root = NULL;
        while (n--)
        {
            SumOfLeafNodes::Node* parent;
            char lr;
            int n1, n2;
            scanf("%d %d %c", &n1, &n2, &lr);
            if (m.find(n1) == m.end())
            {
                parent = new SumOfLeafNodes::Node(n1);
                m[n1] = parent;
                if (root == NULL)
                    root = parent;
            }
            else
                parent = m[n1];
            child = new SumOfLeafNodes::Node(n2);
            if (lr == 'L')
                parent->left = child;
            else
                parent->right = child;
            m[n2] = child;
        }
        cout << SumOfLeafNodes::sumLeaf(root) << endl;
    }
    return 0;

}