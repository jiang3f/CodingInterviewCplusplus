//
// https://practice.geeksforgeeks.org/problems/print-all-nodes-that-dont-have-sibling/1/
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

namespace PrintAllNodesThatDonnotHaveSibling
{
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;
    };
    Node* newNode(int val)
    {
        Node* temp = new Node;
        temp->data = val;
        temp->left = NULL;
        temp->right = NULL;

        return temp;
    }
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

    void nosiblingSub(Node* root, vector<int>& arr)
    {
        if (root == nullptr)    return;

        if (root->left != nullptr)
        {
            if (root->right == nullptr)
            {
                arr.push_back(root->left->data);
            }
            nosiblingSub(root->left, arr);
        }

        if (root->right != nullptr)
        {
            if (root->left == nullptr)
            {
                arr.push_back(root->right->data);
            }
            nosiblingSub(root->right, arr);
        }

            
    }

    vector<int> noSibling(Node* root)
    {
        vector<int> ret;

        if (root == nullptr)    return ret;

        nosiblingSub(root, ret);
       
        if (ret.size() == 0)
        {
            ret.push_back(-1);
        }
        else
        {
            sort(ret.begin(), ret.end());
        }
        return ret;
    }
};

int PrintAllNodesThatDonnotHaveSibling_Test ()
{
    int t;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin, s);
        PrintAllNodesThatDonnotHaveSibling::Node* root = PrintAllNodesThatDonnotHaveSibling::buildTree(s);

        vector<int> res = PrintAllNodesThatDonnotHaveSibling::noSibling(root);
        for (int i = 0; i < res.size(); ++i)
        {
            cout << res[i] << " ";
        }
        cout << endl;
    }
    return 0;
}