//
// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace DiameterOfBinaryTree
{

    /* A binary tree node has data, pointer to left child
       and a pointer to right child */
    struct Node {
        int data;
        struct Node* left;
        struct Node* right;
    };
    Node* newNode(int val) {
        Node* temp = new Node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }
    Node* buildTree(string str) {
        // Corner Case
        if (str.length() == 0 || str[0] == 'N') return NULL;

        // Creating vector of strings from input
        // string after spliting by space
        vector<string> ip;

        istringstream iss(str);
        for (string str; iss >> str;) ip.push_back(str);

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
            if (i >= ip.size()) break;
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

    void diameterSub(struct Node* tree, int& maxLevel, int& maxDiameter)
    {

        if (tree->left == nullptr && tree->right == nullptr)
        {
            maxLevel = 1;
            maxDiameter = 1;
            return;
        }

        int leftLevel, rightLevel;
        int leftDiameter, rightDiameter;

        leftLevel = rightLevel = leftDiameter = rightDiameter = 0;

        if (tree->left != nullptr)
        {
            diameterSub(tree->left, leftLevel, leftDiameter);
        }
        if (tree->right != nullptr)
        {
            diameterSub(tree->right, rightLevel, rightDiameter);
        }

        maxLevel = max(leftLevel, rightLevel) + 1;

        maxDiameter = max(rightDiameter, leftDiameter);

        maxDiameter = max(maxDiameter, leftLevel + rightLevel + 1);
    }
   
    /* Function to get diameter of a binary tree */
    int diameter(struct Node* tree)
    {
        if (tree == nullptr) return 0;

        int level = 0;
        int ret = 0;

        diameterSub(tree, level, ret);

        return ret;
    }

};

int DiameterOfBinaryTree_Test()
{
    int t;
    scanf("%d\n", &t);
    while (t--) {
        string s;
        getline(cin, s);
        DiameterOfBinaryTree::Node* root = DiameterOfBinaryTree::buildTree(s);
        cout << DiameterOfBinaryTree::diameter(root) << endl;
    }
    return 0;
}
