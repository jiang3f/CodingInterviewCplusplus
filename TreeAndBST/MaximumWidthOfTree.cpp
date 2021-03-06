//
// https://practice.geeksforgeeks.org/problems/maximum-width-of-tree/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream
#include <algorithm>


using namespace std;

namespace MaximumWidthOfTree
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

    void getMaxWidthSub(Node* cur, int arr[], int level)
    {
        if (cur == nullptr) return;

        arr[level] ++;

        if (cur->left != nullptr)
        {
            getMaxWidthSub(cur->left, arr, level + 1);
        }

        if (cur->right != nullptr)
        {
            getMaxWidthSub(cur->right, arr, level + 1);
        }

    }

    /* Function to get the maximum width of a binary tree*/
    int getMaxWidth_mine(Node* root)
    {
       
        // Your code here
        int arr[1000];
        for (int i = 0; i < 1000; i++)    arr[i] = 0;

        getMaxWidthSub(root, arr, 1);

        sort(arr, arr + 1000);


        return arr[999];
    }

    //
    // https://ide.geeksforgeeks.org/7mAg70lkJo
    //
    int getMaxWidth(Node* root)
    {
        if (root == NULL)
            return 0;

        queue<Node*> q;
        q.push(root);

        int max = 0;

        while (1)
        {
            int nodeCount = q.size();
            if (nodeCount == 0)
                break;

            if (nodeCount > max)
                max = nodeCount;

            while (nodeCount > 0)
            {
                Node* temp = q.front();
                q.pop();
                if (temp->left)
                    q.push(temp->left);

                if (temp->right)
                    q.push(temp->right);
                nodeCount--;
            }

        }
        return max;
    }

};

int MaximumWidthOfTree_Test ()
{
    char input[20];

    cin.getline(input, sizeof(input));
    int test = atoi(input);
    while (test--)
    {
        string s;

        getline(cin, s);

        MaximumWidthOfTree::Node* root = MaximumWidthOfTree::buildTree(s);

        //int ret = MaximumWidthOfTree::getMaxWidth_mine(root);

        int ret = MaximumWidthOfTree::getMaxWidth(root);

        cout << ret << endl;

    }
    return 0;
}

