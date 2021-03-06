//
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>      // std::istringstream
#include <map>
#include <algorithm>

using namespace std;

namespace BottomViewOfBinaryTree
{
#define MAX_HEIGHT 100000

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

    queue<pair<int, Node*>> bottomViewSub(queue<pair<int, Node*>> q, map<int, int>& bottomViewMap)
    {
        queue<pair<int, Node*>> ret;

        while (q.size() != 0)
        {
            pair<int, Node*> cur = q.front();
            q.pop();

            bottomViewMap[cur.first] = cur.second->data;

            if (cur.second->left != nullptr)
            {
                ret.push(pair<int, Node*>(cur.first - 1, cur.second->left));
            }

            if (cur.second->right != nullptr)
            {
                ret.push(pair<int, Node*>(cur.first + 1, cur.second->right));
            }
        }

        return ret;
    }

    vector <int> bottomView(Node* root)
    {
        vector<int> ret;

        if (root == nullptr)    return ret;

        queue<pair<int,Node*>> q;
        q.push(pair<int, Node*>(0, root));

        map<int, int> bottomViewMap;

        while (q.size() != 0)
        {
            q = bottomViewSub( q, bottomViewMap);
        }

        for (map<int, int>::iterator it = bottomViewMap.begin(); it != bottomViewMap.end(); it++)
        {
            ret.push_back(it->second);
        }

        return ret;
    }
};

int BottomViewOfBinaryTree_Test ()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s, ch;
        getline(cin, s);
        BottomViewOfBinaryTree::Node* root = BottomViewOfBinaryTree::buildTree(s);

        vector <int> res = BottomViewOfBinaryTree::bottomView(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
