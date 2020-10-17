//
// https://practice.geeksforgeeks.org/problems/two-mirror-trees/1/
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

namespace TwoMirrorTrees
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

    int areMirrorSub(queue<Node*>& q1, queue<Node*>& q2)
    {
        int ret = 1;

        int sz1 = q1.size();

        for (int i = 0; i < sz1; i++)
        {

            Node* cur1 = q1.front();
            q1.pop();
            Node* cur2 = q2.front();
            q2.pop();

            if (cur2->data != cur1->data)
            {
                ret = 0;
                break;
            }
            if (cur1->right != nullptr)
            {
                q1.push(cur1->right);
            }
            if (cur1->left != nullptr)
            {
                q1.push(cur1->left);
            }


            if (cur2->left != nullptr)
            {
                q2.push(cur2->left);
            }
            if (cur2->right != nullptr)
            {
                q2.push(cur2->right);
            }

        }

        return ret;
    }

    int areMirror_old (Node* root1, Node* root2)
    {
        int ret = 1;

        if (root1 == nullptr && root2 == nullptr)
        {
            ret = 1;
        }

        else if (root1 != nullptr && root2 == nullptr)
        {
            ret =  0;
        }
        else if (root2 != nullptr && root1 == nullptr)
        {
            ret =  0;
        }
        else
        {
            queue<Node*> q1;
            q1.push(root1);

            queue<Node*>q2;
            q2.push(root2);

            while (q1.size() != 0 && q2.size() != 0)
            {
                ret = areMirrorSub(q1, q2);

                if (ret == 0)   break;
            }

            if (q1.size() != 0 || q2.size() != 0)
            {
                ret = 0;
            }
        }
        return ret;
    }

    int areMirror(Node* root1, Node* root2)
    {
        int ret = 1;

        if (root1 == nullptr && root2 == nullptr)
        {
            ret = 1;
        }

        else if (root1 != nullptr && root2 == nullptr)
        {
            ret = 0;
        }
        else if (root2 != nullptr && root1 == nullptr)
        {
            ret = 0;
        }
        else
        {
            ret = (root1->data == root2->data) ? 1 : 0;

            if (ret == 1)
            {
                ret = areMirror(root1->left, root2->right);

                if (ret == 1)
                {
                    ret = areMirror(root1->right, root2->left);
                }
            }
        }
        return ret;

    }
};

int TwoMirrorTrees_Test ()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString1, treeString2;
        getline(cin, treeString1);
        TwoMirrorTrees::Node* root1 = TwoMirrorTrees::buildTree(treeString1);

        getline(cin, treeString2);
        TwoMirrorTrees::Node* root2 = TwoMirrorTrees::buildTree(treeString2);

        cout << areMirror(root1, root2) << "\n";
    }
    return 0;
}