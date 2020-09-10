//
// https://practice.geeksforgeeks.org/problems/postorder-traversal/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace PostorderTraversal
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

    /* Computes the number of nodes in a tree. */
    vector <int> postOrder_oldold(struct Node* root)
    {
        vector <int> ret;

        if (root == nullptr)    return ret;

        queue<Node*> q;
        q.push(root);

        while (q.size() != 0)
        {
            Node* currentNode = q.front();
            q.pop();

            ret.insert(ret.begin(), currentNode->data);

            if (currentNode->right != nullptr)
            {
                q.push(currentNode->right);
            }
            if (currentNode->left != nullptr)
            {
                q.push(currentNode->left);
            }
        }

        return ret;
    }

    void PostOrderSub(struct Node* root, vector<int>& ret)
    {
        if (root == nullptr)    return;

        if (root->left != nullptr)
        {
            PostOrderSub(root->left, ret);
        }

        if (root->right != nullptr)
        {
            PostOrderSub(root->right, ret);
        }

        ret.push_back(root->data);
    }

    /* Computes the number of nodes in a tree. */
    vector <int> postOrder(struct Node* root)
    {
        vector <int> ret;

        PostOrderSub(root, ret);

        return ret;
    }

};

int PostorderTraversal_Test()
{
    int t;
    cin >> t;
    getchar();
    while (t--)
    {
        string inp;
        getline(cin, inp);
        PostorderTraversal::Node* root = PostorderTraversal::buildTree(inp);

        vector <int> res = PostorderTraversal::postOrder(root);
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
