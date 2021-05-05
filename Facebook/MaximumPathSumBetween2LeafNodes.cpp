/*
* https://www.geeksforgeeks.org/facebook-nyc-onsite-interview-experience/
*/

/*
*
 Given a binary tree in which each node element contains a number. Find the maximum possible sum from one leaf node to another.
 */

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>      // std::istringstream
#include <queue>


using namespace std;

//////////////////////////////////////////////////
// The following anwser IS INCORRECT!!111
/////////////////////////////////////////////////


namespace MaximumPathSumBetween2LeafNodes
{
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
        if (str.length() == 0 || str[0] == 'N') return NULL;

        // Creating vector of strings from input
        // string after spliting by space
        vector<string> ip;

        istringstream iss(str);
        for (string str; iss >> str;) ip.push_back(str);

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

            // Get the current Node's value from the string
            string currVal = ip[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current Node
                currNode->left = new Node(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->left);
            }

            // For the right child
            i++;
            if (i >= ip.size()) break;
            currVal = ip[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current Node
                currNode->right = new Node(stoi(currVal));

                // Push it to the queue
                queue.push(currNode->right);
            }
            i++;
        }

        return root;
    }

    // I got confused when considering maximum path sum between two nodes at left/right.
    // and longest path sum on left/right child

    // so I should have created a sub function to return both.
    // see C:\github\CodingInterviewCplusplus\TreeAndBST\MaximumPathSumBetween2LeafNodes.cpp

    int maxPathSum(Node* root)
    {
        if (root == nullptr)    return INT_MIN;

        int leftMax = 0;
        int rightMax = 0;

        if (root->left != nullptr)
        {
            leftMax = maxPathSum(root->left);
        }

        if (root->right != nullptr)
        {
            rightMax = maxPathSum(root->right);
        }

        int max = (leftMax > rightMax) ? leftMax : rightMax;
        max += root->data;

        return max;

    }

};

int MaximumPathSumBetween2LeafNodes_Test()
{
    /*
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        MaximumPathSumBetween2LeafNodes::Node* root = MaximumPathSumBetween2LeafNodes::buildTree(treeString);
        cout << MaximumPathSumBetween2LeafNodes::maxPathSum(root) << "\n";
    }
    */

    string treeString = "-9 6 -10";
    MaximumPathSumBetween2LeafNodes::Node* root = MaximumPathSumBetween2LeafNodes::buildTree(treeString);
    cout << MaximumPathSumBetween2LeafNodes::maxPathSum(root) << "\n";

    return 0;

};
