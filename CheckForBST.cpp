//
// https://practice.geeksforgeeks.org/problems/check-for-bst/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace CheckForBST
{


#define MAX_HEIGHT 100000

    // Tree Node
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };

    // Function to Build Tree
    Node* buildTree(string str)
    {
        // Corner Case
        if (str.length() == 0 || str[0] == 'N')
            return NULL;

        // Creating vector of strings from input
        // string after spliting by space
        vector<string> ip;

        istringstream iss(str);
        for (string str; iss >> str; )
            ip.push_back(str);

        // Create the root of the tree
        Node* root = new Node(stoi(ip[0]));

        // Push the root to the queue
        queue<Node*> queue;
        queue.push(root);

        // Starting from the second element
        int i = 1;
        while (!queue.empty() && i < ip.size()) {

            // Get and remove the front of the queue
            Node* currNode = queue.front();
            queue.pop();

            // Get the current node's value from the string
            string currVal = ip[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currNode->left = new Node(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= ip.size())
                break;
            currVal = ip[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    void inorder(Node* root, vector<int>& v)
    {
        if (root == NULL)
            return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }

    bool isBstSub(struct Node* node, int value, int mode)
    {
        if (node == nullptr)    return true;

        bool ret = true;

        if (mode == 0)
        {
            if (node->data >= value)
            {
                return false;
            }
        }
        else if (mode == 1)
        {
            if (node->data <= value)
            {
                return false;
            }
        }

        if (node->left != nullptr)
        {
            ret = isBstSub(node->left, node->data, 0);
        }

        if (ret == false)   return false;

        if (node->right != nullptr)
        {
            ret = isBstSub(node->right, node->data, 1);
        }

        return ret;

    }

    int isBSTUtil(struct Node* node, int min, int max)
    {
        if (node == nullptr)    return 1;

        if (node->data < min || node->data > max)   return 0;

        if (isBSTUtil(node->left, min, node->data - 1) == 0)    return 0;

        if (isBSTUtil(node->right, node->data + 1, max) == 0)  return 0;


        return 1;
    }

    bool isBST(struct Node* node)
    {

        if (node == nullptr)    return true;

        //bool ret = isBstSub(node, 0, 3);

        bool ret = (bool)isBSTUtil(node, INT_MIN, INT_MAX);

        return ret;
    }

};

int CheckForBST_Test()
{

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        CheckForBST::Node* root = CheckForBST::buildTree(s);
        cout << CheckForBST::isBST(root) << endl;
    }
    return 0;

}
