/*
* https://www.geeksforgeeks.org/segment-tree-set-1-sum-of-given-range/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


namespace SegTreeSumOfGivenRange
{
    class Solution
    {
    private:
        int ConstructSegTree_Sub(int arr[], int segtree[], int low, int high, int pos)
        {
            if (low == high)
            {
                segtree[pos] = arr[low];
                return segtree[pos];
            }

            int mid = (low + high) / 2;

            segtree[pos] = ConstructSegTree_Sub(arr, segtree, low, mid, 2 * pos + 1) + ConstructSegTree_Sub(arr, segtree, mid + 1, high, 2 * pos + 2);
            return segtree[pos];

        }

    public:
        void ConstructSegTree(int arr[], int n, int *& segtree, int &length)
        {
            // height of the segment tree
            int height = (int)ceil(log2(n));

            length = 2 * (int)pow(2, height) - 1;

            segtree = new int[length];
            memset(segtree, 0, length * sizeof(int));

            ConstructSegTree_Sub(arr, segtree, 0, n-1, 0);
        }

        int GeSum_sub(int segtree[], int low, int high, int qlow, int qhigh, int pos)
        {
            if (qlow <= low && high <= qhigh)
            {
                return segtree[pos];
            }

            else if (qlow > high || qhigh < low)
            {
                return 0;
            }

            else
            {
                int mid = (low + high) / 2;
                return GeSum_sub(segtree, low, mid, qlow, qhigh, 2 * pos + 1) + GeSum_sub(segtree, mid + 1, high, qlow, qhigh, 2 * pos + 2);
            }

        }

        // Return sum of values in array from index low to high
        int GetSum(int segtree[], int n, int qlow, int qhigh)
        {
            if (qlow < 0 || qhigh > n || qlow > qhigh)
            {
                cout << "invalid. " << endl;
                return -1;
            }

            return GeSum_sub (segtree, 0, n - 1, qlow, qhigh, 0);
        }

        int UpdateValue_sub(int segtree[], int low, int high, int pos, int arrayPos, int value)
        {
            if (arrayPos < low || arrayPos> high)
            {
                return segtree[pos];
            }

            else if (low == high)
            {
                segtree[pos] = value;
                return segtree[pos];
            }

            else
            {
                segtree[pos] += value;

                int mid = (low + high) / 2;

                segtree[pos] = UpdateValue_sub(segtree, low, mid, 2*pos+1, arrayPos, value) + UpdateValue_sub(segtree, mid + 1, high, 2*pos+2, arrayPos, value);
            
                return segtree[pos];
            }
        }

        // Update array and corresponding
        // segment tree nodes
        void UpdateValue(int arr[], int segtree[], int n, int pos, int value)
        {
            if (pos >= n)   return;

            arr[pos] = value;

            UpdateValue_sub(segtree, 0, n - 1, 0, pos, value);
        }


        void PrintArray(int arr[], int n)
        {
            for (int i = 0; i < n; i++)   cout << arr[i] << ",";
            cout << endl;
        }
    };
}

int SegTreeSumOfGivenRange_Test()
{   
    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int n = sizeof(arr) / sizeof(arr[0]);

    SegTreeSumOfGivenRange::Solution ob;

    // Build segment tree from given array
    int* segtree=nullptr, length = 0;
    ob.ConstructSegTree(arr, n, segtree, length);

    ob.PrintArray(segtree, length);

    // Print sum of values in array from index 1 to 3
    cout << "Sum of values in given range = " << ob.GetSum(segtree, n, 1, 3) << endl;

    // Update: set arr[1] = 10 and update corresponding
    // segment tree nodes
    ob.UpdateValue(arr, segtree, n, 1, 10);

    ob.PrintArray(segtree, length);

    // Find sum after the value is updated
    cout << "Updated sum of values in given range = "
        << ob.GetSum(segtree, n, 1, 3) << endl;

    return 0;
}

