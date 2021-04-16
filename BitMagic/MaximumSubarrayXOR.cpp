//
// https://www.geeksforgeeks.org/find-the-maximum-subarray-xor-in-a-given-array/

/*
Expected Time Complexity : O(n) 
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace MaximumSubarraytXOR
{
    int Run(int arr[], int n)
    {
        int max = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            int cur_xor = 0;
            for (int j = i; j < n; j++)
            {
                cur_xor = cur_xor ^ arr[j];
                if (cur_xor > max)
                {
                    max = cur_xor;
                }
            }
        }

        return max;
    }
};

namespace MaximumSubarraytXOR_Trie
{

#define INT_SIZE 32

#define COUNT 3


    struct TrieNode
    {
        int data;
        TrieNode* next[2];

        TrieNode()
        {
            data = 0;
            next[0] = nullptr;
            next[1] = nullptr;
        }
    };


    // Function to print binary tree in 2D 
    // It does reverse inorder traversal 
    void print2DUtil(TrieNode* root, int space)
    {
        // Base case 
        if (root == NULL)
            return;

        // Increase distance between levels 
        space += COUNT;

        // Process right child first 
        print2DUtil(root->next[1], space);

        // Print current TrieNode after space 
        // count 
        cout << endl;
        for (int i = COUNT; i < space; i++)
            cout << " ";
        cout << root->data << "\n";

        // Process left child 
        print2DUtil(root->next[0], space);
    }

    // Wrapper over print2DUtil() 
    void print2D(TrieNode* root)
    {
        // Pass initial space count as 0 
        print2DUtil(root, 0);
    }

    void Insert (TrieNode* root, int pre_xor)
    {
        TrieNode* tmp = root;

        for (int i = INT_SIZE-1; i >= 0;i--)
        {
            bool val = pre_xor & (1 << i);

            if (tmp->next[val] == nullptr)
            {
                tmp->next[val] = new TrieNode();
            }

            tmp = tmp->next[val];
        }

        tmp->data = pre_xor;
    }

    // Finds the maximum XOR ending with last number in 
    // prefix XOR 'pre_xor' and returns the XOR of this maximum 
    // with pre_xor which is maximum XOR ending with last element 
    // of pre_xor. 
    int query(TrieNode* root, int pre_xor)
    {
        TrieNode* temp = root;
        for (int i = INT_SIZE - 1; i >= 0; i--)
        {
            // Find current bit in given prefix 
            bool val = pre_xor & (1 << i);

            // Traverse Trie, first look for a 
            // prefix that has opposite bit 
            if (temp->next[1 - val] != NULL)
                temp = temp->next[1 - val];

            // If there is no prefix with opposite 
            // bit, then look for same bit. 
            else if (temp->next[val] != NULL)
                temp = temp->next[val];
        }
        return pre_xor ^ (temp->data);
    }

    int Run (int arr[], int n)
    {
        // Create a Trie and insert 0 into it 
        TrieNode* root = new TrieNode();
        
        Insert(root, 0);

        //print2D(root);

        // Initialize answer and xor of current prefix 
        int result = INT_MIN, pre_xor = 0;

        // Traverse all input array element 
        for (int i = 0; i < n; i++)
        {
            // update current prefix xor and insert it into Trie 
            pre_xor = pre_xor ^ arr[i];
            
            Insert(root, pre_xor);

            //print2D(root);


            // Query for current prefix xor in Trie and update 
            // result if required 
            result = max(result, query(root, pre_xor));
        }

        return result;
    }


};

namespace MaximumSubarraytXOR_Example
{
    // Assumed int size 
#define INT_SIZE 32 

// A Trie Node 
    struct TrieNode
    {
        int value; // Only used in leaf nodes 
        TrieNode* arr[2];
    };

    // Utility function to create a Trie node 
    TrieNode* newNode()
    {
        TrieNode* temp = new TrieNode;
        temp->value = 0;
        temp->arr[0] = temp->arr[1] = NULL;
        return temp;
    }

    // Inserts pre_xor to trie with given root 
    void insert(TrieNode* root, int pre_xor)
    {
        TrieNode* temp = root;

        // Start from the msb, insert all bits of 
        // pre_xor into Trie 
        for (int i = INT_SIZE - 1; i >= 0; i--)
        {
            // Find current bit in given prefix 
            bool val = pre_xor & (1 << i);

            // Create a new node if needed 
            if (temp->arr[val] == NULL)
                temp->arr[val] = newNode();

            temp = temp->arr[val];
        }

        // Store value at leaf node 
        temp->value = pre_xor;
    }

    // Finds the maximum XOR ending with last number in 
    // prefix XOR 'pre_xor' and returns the XOR of this maximum 
    // with pre_xor which is maximum XOR ending with last element 
    // of pre_xor. 
    int query(TrieNode* root, int pre_xor)
    {
        TrieNode* temp = root;
        for (int i = INT_SIZE - 1; i >= 0; i--)
        {
            // Find current bit in given prefix 
            bool val = pre_xor & (1 << i);

            // Traverse Trie, first look for a 
            // prefix that has opposite bit 
            if (temp->arr[1 - val] != NULL)
                temp = temp->arr[1 - val];

            // If there is no prefix with opposite 
            // bit, then look for same bit. 
            else if (temp->arr[val] != NULL)
                temp = temp->arr[val];
        }
        return pre_xor ^ (temp->value);
    }

    // Returns maximum XOR value of a subarray in arr[0..n-1] 
    int maxSubarrayXOR(int arr[], int n)
    {
        // Create a Trie and insert 0 into it 
        TrieNode* root = newNode();
        insert(root, 0);

        // Initialize answer and xor of current prefix 
        int result = INT_MIN, pre_xor = 0;

        // Traverse all input array element 
        for (int i = 0; i < n; i++)
        {
            // update current prefix xor and insert it into Trie 
            pre_xor = pre_xor ^ arr[i];
            insert(root, pre_xor);

            // Query for current prefix xor in Trie and update 
            // result if required 
            result = max(result, query(root, pre_xor));
        }
        return result;
    }

};

int MaximumSubarraytXOR_Test()
{
    int arr[] = { 8, 1, 2, 12 };
    
    int n = sizeof(arr) / sizeof(arr[0]);
    
    //cout << "Max subarray XOR is " << MaximumSubarraytXOR_Example::maxSubarrayXOR(arr, n);
    cout << "Max subarray XOR is " << MaximumSubarraytXOR_Trie::Run (arr, n);

    return 0;
}

