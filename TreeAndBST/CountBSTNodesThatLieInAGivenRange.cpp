//
// https://practice.geeksforgeeks.org/problems/count-bst-nodes-that-lie-in-a-given-range/1/
//
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <string>
#include <sstream>      // std::istringstream

using namespace std;

namespace CountBSTNodesThatLieInAGivenRange
{

    struct Node {
        int data;
        Node* right;
        Node* left;

        Node(int x) {
            data = x;
            right = NULL;
            left = NULL;
        }
    };


    Node* insert(Node* root, int data)
    {
        if (root == NULL)
            root = new Node(data);
        else if (data < root->data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);

        return root;
    }



    int getCountOfNode(Node* root, int l, int h)
    {
        // your code goes here   
        int count = 0;

        if (root == nullptr)    return 0;

        if (root->data >= l && root->data <= h) count++;

        if (root->left != nullptr && root->data >= l)
        {
            count += getCountOfNode(root->left, l, h);
        }

        if (root->right != nullptr && root->data <= h)
        {
            count += getCountOfNode(root->right, l, h);
        }


        return count;
    }

};

int CountBSTNodesThatLieInAGivenRange_Test()
{
    int testcases;
    cin >> testcases;
    while (testcases--)
    {
        CountBSTNodesThatLieInAGivenRange::Node* root = NULL;
        int sizeOfArray;
        cin >> sizeOfArray;
        int *arr = new int[sizeOfArray];

        for (int i = 0; i < sizeOfArray; i++)
            cin >> arr[i];

        for (int i = 0; i < sizeOfArray; i++)
        {
            root = CountBSTNodesThatLieInAGivenRange::insert(root, arr[i]);
        }
        int l, h;
        cin >> l >> h;
        cout << CountBSTNodesThatLieInAGivenRange::getCountOfNode(root, l, h) << endl;

        delete []arr;
    }
    return 0;
}
