//
// https://practice.geeksforgeeks.org/problems/sum-of-left-leaf-nodes/1/
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

namespace SumOfLeftLeafNodes
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

    void inorder(Node* root, vector<int>& v)
    {
        if (root == NULL)
            return;

        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }


    int leftLeavesSumSub(Node* node, bool isleft)
    {
        if (node == nullptr)    return 0;
        if (node->left == nullptr && node->right == nullptr && isleft == true)  return node->data;

        int ret = leftLeavesSumSub(node->left, true);
        ret += leftLeavesSumSub(node->right, false);

        return ret;
    }

    int leftLeavesSum(Node* root)
    {
        if (root == nullptr)    return 0;

        return leftLeavesSumSub(root, false);
    }

};

int SumOfLeftLeafNodes_Test ()
{
    //freopen("input.txt","r", stdin);
     //freopen("output.txt","w", stdout);
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    //cout << t << endl;
    while (t--)
    {
        string s;
        getline(cin, s);
        SumOfLeftLeafNodes::Node* root = SumOfLeftLeafNodes::buildTree(s);

        //getline(cin, s);

        cout << SumOfLeftLeafNodes::leftLeavesSum(root) << endl;

        //cout<<"~"<<endl;
    }
    return 0;
}