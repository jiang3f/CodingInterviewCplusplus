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

namespace PreorderTraversal
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

        // for(string i:ip)
        //     cout<<i<<" ";
        // cout<<endl;
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

    void preorderSub(Node* node, vector<int>& ret)
    {
        if (node == nullptr)   return;

        ret.push_back(node->data);

        preorderSub(node->left, ret);

        preorderSub(node->right, ret);

    }

    vector<int> preorder(struct Node* root)
    {
        vector<int> ret;

        if (root == nullptr)    return ret;

        preorderSub (root, ret);

        return ret;
    }
};

int PreorderTraversal_Test ()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        PreorderTraversal::Node* root = PreorderTraversal::buildTree(s);

        vector<int> res = PreorderTraversal::preorder(root);
        for (int i : res)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}