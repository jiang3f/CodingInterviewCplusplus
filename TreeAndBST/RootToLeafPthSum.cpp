//
// https://practice.geeksforgeeks.org/problems/root-to-leaf-path-sum/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace RootToLeafPthSum
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
    Node* buildTree(string str) {
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

    bool hasPathSumSub(Node* root, int sum, int target)
    {
        bool ret;

        sum += root->data;

        if (root->left == nullptr && root->right == nullptr)
        {
            return (sum == target) ? true : false;
        }

        if (root->left != nullptr)
        {
            ret = hasPathSumSub(root->left, sum, target);
        }

        if (ret == false && root->right != nullptr)
        {
            ret = hasPathSumSub(root->right, sum, target);
        }
        return ret;

    }

    bool hasPathSum(Node* root, int sum)
    {
        bool ret = false;

        if (root == nullptr)    return false;

        ret = hasPathSumSub(root, 0, sum);
        
        return ret;
    }

};

int RootToLeafPthSum_Test ()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        RootToLeafPthSum::Node* root = RootToLeafPthSum::buildTree(treeString);
        int sum;
        scanf("%d ", &sum);
        cout << RootToLeafPthSum::hasPathSum(root, sum) << "\n";
    }
    return 0;
}
