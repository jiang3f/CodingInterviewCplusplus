//
// https://practice.geeksforgeeks.org/problems/right-view-of-binary-tree/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>      // std::istringstream
#include <map>


using namespace std;

namespace RightViewOfBinaryTree
{
    // Tree Node
    struct Node
    {
        int data;
        Node* left;
        Node* right;
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

    queue<Node*> rightViewSub(queue<Node*> q)
    {
        queue<Node*> ret;
        bool isSet = false;
        int rightViewVal = 0;

        while (q.size() != 0)
        {
            Node* cur = q.front();
            q.pop();

            rightViewVal = cur->data;
            isSet = true;

            if (cur->left != nullptr)
            {
                ret.push(cur->left);
            }

            if (cur->right != nullptr)
            {
                ret.push(cur->right);
            }
        }

        if (isSet)  cout << rightViewVal << " ";

        return ret;
    }

    void rightView(struct Node* root)
    {
        if (root == nullptr)    return;

        queue<Node*> q;
        q.push(root);

        while (q.size() != 0)
        {
            q = rightViewSub(q);
        }

    }


};

int RightViewOfBinaryTree_Test ()
{
    int t;
    string  tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        RightViewOfBinaryTree::Node* root = RightViewOfBinaryTree::buildTree(s);

        RightViewOfBinaryTree::rightView(root);
        cout << endl;
    }
    return 0;
}
