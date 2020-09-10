//
// https://practice.geeksforgeeks.org/problems/reverse-level-order-traversal/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace ReverseLevelOrderTraversal
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

    vector<int> reverseLevelOrder(Node* root)
    {
        vector<int> ret;

        if (root == nullptr) return ret;

        queue<Node*> q;
        q.push(root);

        while (q.size() != 0)
        {
            Node* cur = q.front();
            q.pop();

            ret.insert(ret.begin(), cur->data);
            if (cur->right != nullptr)
            {
                q.push(cur->right);
            }
            if (cur->left != nullptr)
            {
                q.push(cur->left);
            }
        }

        return ret;


    }

};

int ReverseLevelOrderTraversal_Test ()
{

    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        ReverseLevelOrderTraversal::Node* root = ReverseLevelOrderTraversal::buildTree(s);
        vector<int> result = ReverseLevelOrderTraversal::reverseLevelOrder(root);
        for (int i = 0; i < result.size(); ++i)
        {
            cout << result[i] << " ";
        }
        cout << endl;
    }
    return 1;
}
