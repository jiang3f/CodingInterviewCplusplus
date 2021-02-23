//
// https://practice.geeksforgeeks.org/problems/serialize-and-deserialize-a-binary-tree/1
/*
*
Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= Number of nodes <= 1000
1 <= Data of a node <= 1000
*/
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <sstream>  

using namespace std;

namespace SerializeAndDeserializeABinaryTree
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

        std::istringstream iss(str);
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
            if (i >= ip.size())
                break;
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

    void inorder(Node* root) {
        if (root == NULL)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void _deleteTree(Node* node)
    {
        if (node == NULL) return;

        /* first delete both subtrees */
        _deleteTree(node->left);
        _deleteTree(node->right);

        /* then delete the node */
        //cout << "Deleting node: " << node->data << endl;  
        delete node;
    }

    /* Deletes a tree and sets the root as NULL */
    void deleteTree(Node** node_ref)
    {
        _deleteTree(*node_ref);
        *node_ref = NULL;
    }

    /*this  function serializes
    the binary tree and stores
    it in the vector A*/
    class Solution
    {
    public:
        vector<int> serialize(Node* root)
        {
            //Your code here
            vector<int> ret;

            if (root == nullptr)   return ret;

            if (root->left != nullptr)
            {
                vector<int> v = serialize(root->left);
                for (int i = 0; i < v.size(); i ++)
                {
                    ret.push_back(v[i]);
                }
            }
            ret.push_back(root->data);

            if (root->right != nullptr)
            {
                vector<int> v = serialize(root->right);
                for (int i = 0; i < v.size(); i++)
                {
                    ret.push_back(v[i]);
                }
            }
            return ret;
        }

        Node* deSerializeSub(vector<int>& A, int begin, int end)
        {
            int len = end - begin + 1;
            Node* ret = nullptr;

            if (len == 1)
            {
                ret = new Node(A[begin]);
                return ret;
            }

            int nLeaf = 1;
            int completeLeaf = 1;
            while (len > completeLeaf)
            {
                nLeaf = nLeaf * 2;
                completeLeaf += nLeaf;
            }

            int rootPos = begin + completeLeaf / 2;
            ret = new Node(A[rootPos]);

            ret->left = deSerializeSub(A, begin, rootPos - 1);
            ret->right = deSerializeSub(A, rootPos + 1, end);

            return ret;
        }

        /*this function deserializes
         the serialized vector A*/
        Node* deSerialize(vector<int>& A)
        {
            //Your code here
            if (A.size() == 0)   return nullptr;

            Node* ret = deSerializeSub(A, 0, A.size()-1);

            return ret;
        }
    };


};

int SerializeAndDeserializeABinaryTree_Test ()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        SerializeAndDeserializeABinaryTree::Node* root = SerializeAndDeserializeABinaryTree::buildTree(treeString);

        SerializeAndDeserializeABinaryTree::Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        SerializeAndDeserializeABinaryTree::deleteTree(&root);
        SerializeAndDeserializeABinaryTree::Node* getRoot = deserial.deSerialize(A);
        SerializeAndDeserializeABinaryTree::inorder(getRoot);
        cout << "\n";

    }


    return 0;
}  // } Driver Code Ends