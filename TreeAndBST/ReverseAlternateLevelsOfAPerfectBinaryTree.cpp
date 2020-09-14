//
// https://practice.geeksforgeeks.org/problems/reverse-alternate-levels-of-a-perfect-binary-tree/1/
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

namespace ReverseAlternateLevelsOfAPerfectBinaryTree
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

    void inorder(Node* node)
    {
        if (node == NULL)
            return;

        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    stack<Node*> reverseAlternateSub(stack<Node*> s, vector<Node *>& arr, int level, bool reverse)
    {
        stack<Node*>ret;

        for (int i = 0 ; i < (1 << level); i++)
        {
            Node* cur = s.top();
            s.pop();

            arr.push_back(cur);

            if (level > 0)
            {
                Node* parentNode = arr[(1 << (level - 1)) - 1 + i / 2];
                if (i % 2 == 0)
                {
                    parentNode->left = cur;
                }
                else
                {
                    parentNode->right = cur;
                }
            }

            if (!reverse)
            {
                if (cur->left != nullptr)
                {
                    ret.push(cur->left);
                }
                if (cur->right != nullptr)
                {
                    ret.push(cur->right);
                }
            }
            else
            {
                if (cur->right != nullptr)
                {
                    ret.push(cur->right);
                }
                if (cur->left != nullptr)
                {
                    ret.push(cur->left);
                }
            }
        }
        return ret;
    }

    void reverseAlternate(struct Node* root)
    {
        if (root == nullptr)    return;

        stack<Node*>s;
        s.push(root);

        vector<Node*> arr;

        int level = 0;
        bool reverse = false;

        while (s.size() != 0)
        {
            s = reverseAlternateSub(s, arr, level, reverse);

            level++;

            reverse = reverse ? false : true;
        }

    }

};

int ReverseAlternateLevelsOfAPerfectBinaryTree_Test()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        ReverseAlternateLevelsOfAPerfectBinaryTree::Node* root = ReverseAlternateLevelsOfAPerfectBinaryTree::buildTree(s);
        ReverseAlternateLevelsOfAPerfectBinaryTree::reverseAlternate(root);
        ReverseAlternateLevelsOfAPerfectBinaryTree::inorder(root);
        cout << endl;
    }
    return 1;
}
