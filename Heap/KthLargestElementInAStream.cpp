//
// https://practice.geeksforgeeks.org/problems/kth-largest-element-in-a-stream2220/1
/*
*
Expected Time Complexity: O(n)
Expected Auxiliary Space: O(n)



Constraints:
1 <= k <= n <= 5 power of 10
1 <= arr[i] <= 5 power of 10

*/
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace KthLargestElementInAStream
{
    struct MinHeapNode
    {
        int data;
        int id;
        MinHeapNode(int _data, int _id)
        {
            data = _data;
            id = _id;
        }
    };

    struct compare
    {
        bool operator()(MinHeapNode* l, MinHeapNode* r)
        {
            return (l->data > r->data);
        }

    };

    class Solution
    {
    private:

        priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;

    public:
        vector<int> kthLargest(int k, int arr[], int n) 
        {
            // code here
            vector<int> ret;

            for (int i = 0; i < n; i++)
            {
                minHeap.push(new MinHeapNode(arr[i], i));
            }


            int* sortArr = new int[n];

            int i = 0;
            while (minHeap.size() != 0)
            {
                MinHeapNode* node = minHeap.top();
                minHeap.pop();
                
                sortArr[i] = node->data;

                if (i < k - 1)
                {
                    ret.push_back(-1);
                }
                else
                {
                    ret.push_back(sortArr[i - k + 1]);
                }
                i++;
            }
            return ret;

        }
    };
};

int KthLargestElementInAStream_Test()
{
    int t;
    cin >> t;
    while (t--) {
        int k, n;
        cin >> k >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        KthLargestElementInAStream::Solution ob;
        vector<int> v = ob.kthLargest(k, arr, n);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }
    return 0;
}
