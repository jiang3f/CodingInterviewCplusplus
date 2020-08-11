//
// https://practice.geeksforgeeks.org/problems/ancestors-in-binary-tree/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace AncestorsInBinaryTree
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

    bool Sub(struct Node* root, vector<int> ancestor, int target)
    {
        if (root == NULL)   return false;

        if (root->data == target)
        {
            for (int i = ancestor.size()-1; i>= 0; i--)
            {
                cout << ancestor[i] << " ";
            }
            
            return true;

        }
        else
        {
            ancestor.push_back(root->data);

            bool ret = Sub(root->left, ancestor, target);

            if (ret == true)    return true;
            else
            {
                return Sub(root->right, ancestor, target);
            }
        }
    }
    // Function should print all the ancestor of the target node
    bool printAncestors(struct Node* root, int target)
    {
        // Code here
        
        vector<int> ancestor;

        bool ret = Sub(root, ancestor, target);

        return ret;
    }
};

int AncestorsInBinaryTree_Test ()
{
    char input[20];

    cin.getline(input, sizeof(input));
    int test = atoi(input);
    while (test--)
    {
        string s;

        getline(cin, s);

        cin.getline(input, sizeof(input));

        int target = atoi(input);

        AncestorsInBinaryTree::Node* root = AncestorsInBinaryTree::buildTree(s);

        AncestorsInBinaryTree::printAncestors(root, target);

        cout << endl;


    }
    return 0;
}

