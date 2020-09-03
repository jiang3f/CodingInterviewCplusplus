//
// https://practice.geeksforgeeks.org/problems/root-to-leaf-paths/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace RootToLeafPaths
{
#define MAX_HEIGHT 100000

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


    vector<vector<int>> Paths(Node* root);

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

    vector<vector<int>> PathsSub(Node* root, vector<int> path)
    {
        vector<vector<int>> ret;

        if (root == nullptr)
        {
            return ret;
        }

        path.push_back(root->data);

        if (root->left == nullptr && root->right == nullptr)
        {
            ret.push_back(path);
            return ret;
        }

        if (root->left != nullptr)
        {
            ret = PathsSub(root->left, path);
        }
        if (root->right != nullptr)
        {
            vector<vector<int>> right = PathsSub(root->right, path);
            ret.insert(ret.end(), right.begin(), right.end());
        }
        return ret;

    }

    /* The function should print all the paths from root
        to leaf nodes of the binary tree */
    vector<vector<int>> Paths(Node* root)
    {
        // Code here
        vector<vector<int>> ret;

        if (root == NULL) return ret;

        vector<int> path;

        ret = PathsSub(root, path);

        return ret;
    }
};

int RootToLeafPaths_Test()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        RootToLeafPaths::Node* root = RootToLeafPaths::buildTree(s);

        vector<vector<int>> paths = RootToLeafPaths::Paths(root);
        for (int i = 0; i < paths.size(); i++) {
            for (int j = 0; j < paths[i].size(); j++) {
                cout << paths[i][j] << " ";
            }
            cout << "#";
        }
        cout << "\n";
    }
    return 0;
}
