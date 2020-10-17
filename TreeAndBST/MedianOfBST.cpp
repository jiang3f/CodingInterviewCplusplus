//
// https://practice.geeksforgeeks.org/problems/median-of-bst/1/
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

namespace MedianOfBST
{
#define MAX_HEIGHT 100000

    // Tree Node
    struct Node {
        int data;
        Node* left;
        Node* right;

        Node(int val) {
            data = val;
            left = right = NULL;
        }
    };



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

    void findMedianSub(Node* node, vector<int>& arr)
    {
        if (node == nullptr)    return;

        if (node->left != nullptr)
        {
            findMedianSub(node->left, arr);
        }
        arr.push_back(node->data);
        if (node->right != nullptr)
        {
            findMedianSub(node->right, arr);
        }
    }

    float findMedian(struct Node* node)
    {
        if (node == nullptr)    return 0.0;

        vector<int> arr;

        findMedianSub(node, arr);

        float ret = 0.0;

        size_t sz = arr.size();
        if ((sz % 2) == 0)
        {
            ret = ((float)arr[sz / 2 - 1] + (float)arr[sz / 2]) / 2;
        }
        else
        {
            ret = (float)(arr[sz / 2 ]);
        }


        return ret;
    }

};

int MedianOfBST_Test()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    //cout << t << endl;
    while (t--)
    {
        string s;
        getline(cin, s);
        MedianOfBST::Node* root = MedianOfBST::buildTree(s);

        // getline(cin, s);

        cout << MedianOfBST::findMedian(root) << endl;

        // cout<<"~"<<endl;
    }
    return 0;
}
