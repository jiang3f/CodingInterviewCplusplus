//
// https://practice.geeksforgeeks.org/problems/mirror-tree/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>      // std::istringstream
#include <map>
#include <deque>


using namespace std;

namespace MirrorTree
{

    /* A binary tree node has data, pointer to left child
       and a pointer to right child */
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;

        Node(int x) {
            data = x;
            left = right = NULL;
        }
    };

    // Function to Build Tree
    Node* buildTree(string str) {
        // Corner Case
        if (str.length() == 0 || str[0] == 'N')
            return NULL;

        // Creating vector of strings from input
        // string after spliting by space
        vector<string> ip;

        istringstream iss(str);
        for (string str; iss >> str;)
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

    /* Helper function to test mirror(). Given a binary
       search tree, print out its data elements in
       increasing sorted order.*/
    void inOrder(struct Node* node)
    {
        if (node == NULL)
            return;

        inOrder(node->left);
        printf("%d ", node->data);

        inOrder(node->right);
    }

    queue<Node*> mirrorSub(queue<Node*> q)
    {
        queue<Node*> ret;

        while (q.size() != 0)
        {
            Node* cur = q.front();
            q.pop();

            if (cur->right != nullptr)
            {
                ret.push(cur->right);
            }
            if (cur->left != nullptr)
            {
                ret.push(cur->left);
            }
            
            Node* tmp = cur->left;
            cur->left = cur->right;
            cur->right = tmp;
        }

        return ret;
    }

    void mirror(struct Node* node)
    {
        if (node == nullptr)    return;

        queue <Node*> q;
        q.push(node);

        while (q.size() != 0)
        {
            q = mirrorSub(q);
        }

    }


};

int MirrorTree_Test ()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str;
        getline(cin, str);
        MirrorTree::Node* root = MirrorTree::buildTree(str);
        MirrorTree::mirror(root);
        MirrorTree::inOrder(root);
        cout << "\n";
    }


    return 0;

}