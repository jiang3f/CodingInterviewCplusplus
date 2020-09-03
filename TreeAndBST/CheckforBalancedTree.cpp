//
// https://practice.geeksforgeeks.org/problems/check-for-balanced-tree/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace CheckforBalancedTree
{
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;
    };
    // Utility function to create a new Tree Node
    Node* newNode(int val)
    {
        Node* temp = new Node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
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
        Node* root = newNode(stoi(ip[0]));

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
                currNode->left = newNode(stoi(currVal));

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
                currNode->right = newNode(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    int MaxLevel (Node* root, int max)
    {
        max++;

        if (root->left == nullptr && root->right == nullptr)
        {
            return max;
        }

        int leftMax, rightMax;
        leftMax = rightMax = max;

        if (root->left != nullptr)
        {
            leftMax = MaxLevel(root->left, max);
            if (leftMax == -1)   return -1;
        }

        if (root->right != nullptr)
        {
            rightMax = MaxLevel(root->right, max);
            if (rightMax == -1)  return -1;
        }

        if (abs(leftMax - rightMax) > 1) return -1;

        else return (leftMax > rightMax) ? leftMax : rightMax;

    }

    bool isBalanced(Node* root)
    {
        bool ret = false;

        if (root == nullptr)
        {
            return true;
        }

        if (MaxLevel(root, 0) == -1)   return false;
        else return true;
    }
    ;
};  

namespace CheckforBalancedTree_Other
{
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;
    };
    // Utility function to create a new Tree Node
    Node* newNode(int val)
    {
        Node* temp = new Node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
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
        Node* root = newNode(stoi(ip[0]));

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
                currNode->left = newNode(stoi(currVal));

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
                currNode->right = newNode(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }
    
    int isBalancedCheck(Node* root)
    {
        if (root == NULL)
        {
            return 0;
        }

        int lh = isBalancedCheck(root->left);
        if (lh == -1)
        {
            return -1;
        }

        int rh = isBalancedCheck(root->right);
        if (rh == -1)
        {
            return -1;
        }

        if (abs(lh - rh) > 1)
        {
            return -1;
        }
        else
        {
            return 1 + max(lh, rh);
        }
    }

    bool isBalanced(Node* root)
    {
        if (isBalancedCheck(root) == -1)
        {
            return false;
        }
        return true;
    }

};
int CheckforBalancedTree_Test()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        CheckforBalancedTree::Node* root = CheckforBalancedTree::buildTree(s);
        cout << CheckforBalancedTree::isBalanced(root) << endl;
    }
    return 1;
}
