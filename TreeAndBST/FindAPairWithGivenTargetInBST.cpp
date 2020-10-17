//
// https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1/
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

namespace FindAPairWithGivenTargetInBST
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
    
        bool Merge(int data, vector<int> left, vector<int>right, int k, vector<int>& all )
        {
            for (int i = 0; i < left.size(); i++)
            {
                if ((data + left[i]) == k)
                {
                    //cout << data << " + " << left[i] << " = " << k << endl;
                    return true;
                }
            }
            for (int i = 0; i < right.size(); i++)
            {
                if ((data + right[i]) == k)
                {
                    //cout << data << " + " << right[i] << " = " << k << endl;
                    return true;;
                }
            }

            for (int i = 0; i < left.size(); i++)
            {
                for (int j = 0; j < right.size(); j++)
                {
                    if (left[i] + right[j] == k)
                    {
                       // cout << left[i] << " + " << right[j] << " = " << k << endl;
                        return true;
                    }
                }
            }
            all.push_back(data);
            for (int i = 0; i < left.size(); i++) all.push_back(left[i]);
            for (int i = 0; i < right.size(); i++)   all.push_back(right[i]);
            
            return false;
        }

        int isPairPresentSub(Node* node, int k, vector<int>& arr)
        {
            if (node == nullptr)    return 0;

            vector<int>left, right;

            if (isPairPresentSub(node->left, k, left) == 1)
            {
                return 1;
            }
            if (isPairPresentSub(node->right, k, right) == 1)
            {
                return 1;
            }
     
            if (Merge(node->data, left, right, k, arr) == true)
            {
                return 1;
            }
            else return 0;
        }

        int isPairPresent(Node* root, int k)
        {
            if (root == nullptr)    return 0;

            vector<int> arr;

            int ret = isPairPresentSub (root, k, arr) ;
        
            return ret;
        }
};

namespace FindAPairWithGivenTargetInBST_FromComments
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


    void inorder(struct Node* root, vector <int>& v) {
        if (root == NULL) return;
        inorder(root->left, v);
        v.push_back(root->data);
        inorder(root->right, v);
    }


    int isPairPresent(struct Node* root, int target)
    {
        if (root == NULL) return 0;
        vector  <int> v;
        inorder(root, v);
        int n = v.size();
        int l = 0, r = n - 1, sum = 0;
        while (l < r) {
            sum = v[l] + v[r];
            if (sum == target) {
                return 1;
            }
            else if (sum > target) {
                r--;
            }
            else {
                l++;
            }
        }
        return 0;
    }
}
int FindAPairWithGivenTargetInBST_Test()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        FindAPairWithGivenTargetInBST_FromComments::Node* root = FindAPairWithGivenTargetInBST_FromComments::buildTree(s);

        getline(cin, s);
        int k = stoi(s);
        //getline(cin, s);

        cout << FindAPairWithGivenTargetInBST_FromComments::isPairPresent(root, k) << endl;
        //cout<<"~"<<endl;
    }
    return 0;
}
