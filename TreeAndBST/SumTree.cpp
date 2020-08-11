//
// https://practice.geeksforgeeks.org/problems/sum-tree/1/
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace SumTree
{
    struct Node
    {
        int data;
        struct Node* left;
        struct Node* right;
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

    // Should return true if tree is Sum Tree, else false
    bool isSumTree(Node* root)
    {

        // Your code here
        int v = root->data;

        Node* left = root->left;
        Node* right = root->right;

        if (left == NULL && right == NULL)  return true;

        int sum = 0;
        if (left != NULL)
        {
            if (isSumTree(left) == false)  return false;

            sum += left->data;

            if (left->left != NULL || left->right != NULL)
            {
                sum += left->data;
            }
        }
        if (right != NULL)
        {
            if (isSumTree(right) == false)   return false;

            sum += right->data;

            if (right->left != NULL || right->right != NULL)
            {
                sum += right->data;
            }
        }

        if (v == sum)   return true;
        else return false;
    }

	int Run(Node * root)
	{

		bool ret = isSumTree( root );

		return (ret == true) ? 1 : 0;
	}

};

int SumTree_Test()
{
    char input[20];

    cin.getline(input, sizeof(input));
    int test = atoi(input);
	while (test--)
	{
        string s;

        getline(cin, s);
        
        SumTree::Node* root = SumTree::buildTree(s);

		int ret = SumTree::Run(root);

		cout << ret << endl;

	}
	return 0;
}

