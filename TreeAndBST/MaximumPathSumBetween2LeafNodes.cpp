//
// https://practice.geeksforgeeks.org/problems/maximum-path-sum/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>      // std::istringstream
#include <map>


using namespace std;

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

    void maxPathSumSub(Node* node, int& maxsum, int& maxdeep)
    {
        if (node == nullptr)
        {
            maxsum = maxdeep = INT_MIN;
            return;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            maxdeep = node->data;
            maxsum = INT_MIN;
            return;
        }
        
        int leftMaxSum, rightMaxSum, leftMaxDeep, rightMaxDeep;

        maxPathSumSub(node->left, leftMaxSum, leftMaxDeep);

        maxPathSumSub(node->right, rightMaxSum, rightMaxDeep);

        if (node->left != nullptr && node->right != nullptr)
        {
            maxsum = (leftMaxSum > rightMaxSum) ? leftMaxSum : rightMaxSum;
            if ((leftMaxDeep + rightMaxDeep + node->data) > maxsum)
            {
                maxsum = leftMaxDeep + rightMaxDeep + node->data;
            }

            maxdeep = (leftMaxDeep > rightMaxDeep) ? leftMaxDeep : rightMaxDeep;
        }
        else if (node->left != nullptr)
        {
            maxsum = leftMaxSum;
            if (maxsum < leftMaxSum)
            {
                maxsum = leftMaxSum;
            }
            maxdeep = leftMaxDeep;
        }
        else
        {
            maxsum = rightMaxSum;
            if (maxsum < rightMaxSum)
            {
                maxsum = rightMaxSum;
            }
            maxdeep = rightMaxDeep;
        }

        maxdeep += node->data;
    }

    int maxPathSum(Node* root)
    {
        if (root == nullptr)    return 0;

        int maxsum = 0;
        int maxdeep = 0;

        maxPathSumSub(root, maxsum, maxdeep);

        return maxsum;
    }
};

int MaximumPathSumBetween2LeafNodes_Test()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        MaximumPathSumBetween2LeafNodes::Node* root = MaximumPathSumBetween2LeafNodes::buildTree(treeString);
        cout << MaximumPathSumBetween2LeafNodes::maxPathSum(root) << "\n";
    }
    return 0;
}
