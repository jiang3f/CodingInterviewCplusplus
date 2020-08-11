//
// https://practice.geeksforgeeks.org/problems/k-distance-from-root/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace KDistanceFromRoot
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

    void Sub(struct Node* root, int level, int k)
    {
        if (root == NULL)   return;

        if (level == k)
        {
            cout << root->data << " ";
            return;
        }
        else
        {
            Sub(root->left, level + 1, k);
            Sub(root->right, level + 1, k);
        }

    }
    void printKdistance(struct Node* root, int k)
    {
        Sub(root, 0, k);
    }
};

int KDistanceFromRoot_Test()
{
    char input[20];

    cin.getline(input, sizeof(input));
    int test = atoi(input);
    while (test--)
    {
        cin.getline(input, sizeof(input));

        int key = atoi(input);

        string s;

        getline(cin, s);

        KDistanceFromRoot::Node* root = KDistanceFromRoot::buildTree(s);

        KDistanceFromRoot::printKdistance(root, key);


    }
    return 0;
}

