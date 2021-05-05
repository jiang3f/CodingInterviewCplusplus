//
// https://www.geeksforgeeks.org/amazon-interview-experience-for-sde-ii-virtual-rounds/?ref=feed
// 

/*
*
*
Given a binary tree with the following TreeTreeNode, create a copy of the tree without using any extra space.

       TreeTreeNode{
              left*, right*, random*, val
       }
* 
*/

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
#include <sstream>      // std::istringstream


using namespace std;
namespace CopyBinaryTree
{
    struct TreeNode
    {
        TreeNode* left, * right;
        TreeNode* random;

        int val;
        TreeNode(int v)
        {
            left = nullptr;
            right = nullptr;
            random = nullptr;
            val = v;
        }
    };
    
    // helper
    TreeNode* buildTree(string str)
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
        TreeNode* root =  new TreeNode(stoi(ip[0]));

        // Push the root to the queue
        queue<TreeNode*> queue;
        queue.push(root);

        // Starting from the second element
        int i = 1;
        while (!queue.empty() && i < ip.size()) {

            // Get and remove the front of the queue
            TreeNode* currTreeNode = queue.front();
            queue.pop();

            // Get the current node's value from the string
            string currVal = ip[i];

            // If the left child is not null
            if (currVal != "N") {

                // Create the left child for the current node
                currTreeNode->left = new TreeNode (stoi(currVal));

                // Push it to the queue
                queue.push(currTreeNode->left);
            }

            // For the right child
            i++;
            if (i >= ip.size())
                break;
            currVal = ip[i];

            // If the right child is not null
            if (currVal != "N") {

                // Create the right child for the current node
                currTreeNode->right = new TreeNode (stoi(currVal));

                // Push it to the queue
                queue.push(currTreeNode->right);
            }
            i++;
        }

        return root;
    }

    void CopyTree (TreeNode* a, TreeNode*& b)
    {
        if (a == nullptr)   return;

        b = new TreeNode(a->val);

        if (a->left != nullptr) CopyTree(a->left, b->left);

        if (a->right != nullptr) CopyTree(a->right, b->right);

    }

    TreeNode* FindNode(TreeNode* node, TreeNode* a, TreeNode* b)
    {
        if (node == nullptr)    return nullptr;
        
        if (a == nullptr)   return nullptr;

        if (a == node)  return b;

        TreeNode* ret;

        if (a->left != nullptr)
        {
            ret = FindNode(node, a->left, b->left);
            if (ret != nullptr) return ret;
        }
        if (a->right != nullptr)
        {
            ret = FindNode(node, a->right, b->right);
            if (ret != nullptr) return ret;
        }

        return nullptr;
    }

    void AssignRandomPointers(TreeNode* a, TreeNode* b, TreeNode *rootA, TreeNode* rootB)
    {
        if (a == nullptr)   return;

        TreeNode* random = a->random;
        
        TreeNode* nodeInNewTree = FindNode(random, rootA, rootB);

        b->random = nodeInNewTree;

        if (a->left != nullptr) AssignRandomPointers (a->left, b->left, rootA, rootB);

        if (a->right != nullptr) AssignRandomPointers (a->right, b->right, rootA, rootB);

    }
};

int CopyBinaryTree_Test()
{

    string s = "4 8 10 7 5 1 3";

    CopyBinaryTree::TreeNode* old = CopyBinaryTree::buildTree(s);

    CopyBinaryTree::TreeNode* newTree = nullptr;


    // copy left and right leaves
    CopyBinaryTree::CopyTree(old, newTree);

    // traversal to assign the random pointer

    CopyBinaryTree::AssignRandomPointers(old, newTree, old, newTree);


    return 0;
}
