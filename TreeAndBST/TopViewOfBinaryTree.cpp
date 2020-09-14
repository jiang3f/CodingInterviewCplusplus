//
// https://practice.geeksforgeeks.org/problems/top-view-of-binary-tree/1/
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

namespace TopViewOfBinaryTree
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

    queue<pair<int, Node*>> topViewSub(queue<pair<int, Node*>> q, map<int, int>& topViewMap)
    {
        queue<pair<int, Node*>> ret;

        while (q.size() != 0)
        {
            pair<int, Node*> cur = q.front();
            q.pop();

            if (topViewMap.find(cur.first) == topViewMap.end())
            {
                topViewMap[cur.first] = cur.second->data;
            }

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

    void topView(struct Node* root)
    {
        if (root == nullptr)    return;

        queue<pair<int, Node*>>q;
        q.push(pair<int, Node*>(0, root));

        map<int, int> topViewMap;

        while (q.size() != 0)
        {
            q = topViewSub(q, topViewMap);
        }

        for (map<int, int>::iterator it = topViewMap.begin(); it != topViewMap.end(); it++)
        {
            cout << it->second << " ";
        }
    }


};

int TopViewOfBinaryTree_Test ()
{
    int t; cin >> t;
    while (t--)
    {
        int n, i, k;
        cin >> n;
        i = n;

        TopViewOfBinaryTree::Node* root = NULL;
        queue <TopViewOfBinaryTree::Node*> q;
        while (i > 0)
        {
            int a, b;
            char c;
            cin >> a >> b >> c;
            if (!root) {
                root = new TopViewOfBinaryTree::Node(a);
                q.push(root);
            }
            TopViewOfBinaryTree::Node* pick = q.front();
            q.pop();

            if (c == 'L') {
                pick->left = new TopViewOfBinaryTree::Node(b);
                q.push(pick->left);
            }
            cin >> a >> b >> c;
            if (c == 'R') {
                pick->right = new TopViewOfBinaryTree::Node(b);
                q.push(pick->right);
            }
            i -= 2;
        }
        //        inorder(root);
        //        cout<<endl;
        TopViewOfBinaryTree::topView(root);
        cout << endl;
    }
    return 0;
}
