//
// https://practice.geeksforgeeks.org/problems/determine-if-two-trees-are-identical/1/
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

namespace DetermineIfTwoTreesAreIdentical
{
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;

        Node(int x) {
            data = x;
            left = NULL;
            right = NULL;
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

    bool isIdentical(Node* a, Node* b)
    {
        if (a == nullptr && b == nullptr)   return true;
        else if (a == nullptr && b != nullptr)  return false;
        else if (a != nullptr && b == nullptr)  return false;
        else
        {
            bool ret = a->data == b->data;
            if (ret == true)
            {
                ret = isIdentical(a->left, b->left);
                if (ret == true)
                {
                    ret = isIdentical(a->right, b->right);
                }
            }
            return ret;
        }
    }

};

int DetermineIfTwoTreesAreIdentical_Test ()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string str, str1;
        getline(cin, str);
        DetermineIfTwoTreesAreIdentical::Node* rootA = DetermineIfTwoTreesAreIdentical::buildTree(str);
        getline(cin, str1);
        DetermineIfTwoTreesAreIdentical::Node* rootB = DetermineIfTwoTreesAreIdentical::buildTree(str1);
        if (DetermineIfTwoTreesAreIdentical::isIdentical(rootA, rootB)) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
    }
    return 0;
}