/*
* https://www.youtube.com/watch?v=xuoQdt5pHj0
* https://github.com/mission-peace/interview/blob/master/src/com/interview/tree/SegmentTreeMinimumRangeQuery.java
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


namespace SegmentTreeMinimumRangeQuery
{
    class Solution
    {
    private:
        void CreateSegmentTree_sub(int segtree[], int input[], int low, int high, int pos)
        {
            if (low == high)
            {
                segtree[pos] = input[low];
                return;
            }

            int mid = (low + high) / 2;
            
            CreateSegmentTree_sub(segtree, input, low, mid, 2 * pos + 1);

            CreateSegmentTree_sub(segtree, input, mid + 1, high, 2 * pos + 2);
        
            segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);

            return;
        }

        int RangeMinimumQuery_sub(int segtree[], int low, int high, int qlow, int qhigh, int pos)
        {
            // total overlapp
            if (qlow <= low && qhigh >= high)
            {
                return segtree[pos];
            }

            // no overlapping
            if (qlow > high || qhigh < low)
            {
                return INT_MAX;
            }

            int mid = (low + high) / 2;

            return min(RangeMinimumQuery_sub(segtree, low, mid, qlow, qhigh, 2 * pos + 1), RangeMinimumQuery_sub(segtree, mid + 1, high, qlow, qhigh, 2 * pos + 2));
        }

        void UpdateSegmentTree_sub(int segtree[], int index, int value, int low, int high, int pos)
        {
            if (pos < low || pos > high)    return;

            if (low == high)
            {
                segtree[pos] += value;

                return ;
            }

            int mid = (low + high) / 2;

            UpdateSegmentTree_sub(segtree, index, value, low, mid, 2 * pos + 1);

            UpdateSegmentTree_sub(segtree, index, value, mid + 1, high, 2 * pos + 2);

            segtree[pos] = min(segtree[2*pos+1], segtree[2*pos+2]);

            return ;
        }

        void UpdateSegmentTreeRange_sub(int segtree[], int low, int high, int rangelow, int rangehigh, int pos, int value)
        {
            if (rangelow > high || rangehigh < low) return;

            if (low == high)
            {
                segtree[pos] += value;
            
                return;
            }

            int mid = (low + high) / 2;

            UpdateSegmentTreeRange_sub(segtree, low, mid, rangelow, rangehigh, 2 * pos + 1, value);

            UpdateSegmentTreeRange_sub(segtree, mid + 1, high, rangelow, rangehigh, 2 * pos + 2, value);

            segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);

            return;

        }

        void UpdateSegmentTreeRangeLazy_sub(int segtree[], int lazy[], int rangelow, int rangehigh, int value, int low, int high, int pos)
        {
            if (low > rangehigh || high < rangelow) return;

            if (low == high)
            {
                if (lazy[pos] != 0)
                {
                    segtree[pos] += lazy[pos];

                    lazy[pos] = 0;
                }

                segtree[pos] += value;

                return;
            }


            if (low >= rangelow && high <= rangehigh)
            {
                if (lazy[pos] != 0)
                {
                    segtree[pos] += lazy[pos];

                    lazy[2 * pos + 1] += lazy[pos];
                    
                    lazy[2 * pos + 2] += lazy[pos];

                    lazy[pos] = 0;
                }

                segtree[pos] += value;

                lazy[2 * pos + 1] += value;

                lazy[2 * pos + 2] += value;

                return;
            }

            int mid = (low + high) / 2;

            UpdateSegmentTreeRangeLazy_sub (segtree, lazy, rangelow, rangehigh, value, low, mid, 2 * pos + 1);

            UpdateSegmentTreeRangeLazy_sub (segtree, lazy, rangelow, rangehigh, value, mid+1, high, 2 * pos + 2);

            segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);

            return;
        }

        int RangeMinimumQueryLazy_sub(int segtree[], int lazy[], int rangelow, int rangehigh, int low, int high, int pos)
        {
            if (low > rangehigh || high < rangelow) return INT_MAX;

            if (low >= rangelow || high <= rangehigh)
            {
                if (lazy[pos] > 0)
                {
                    segtree[pos] += lazy[pos];

                    lazy[2 * pos + 1] += lazy[pos];

                    lazy[2 * pos + 2] += lazy[pos];

                    lazy[pos] = 0;
                }

                return segtree[pos];
            }

            int mid = (low + high) / 2;

            RangeMinimumQueryLazy_sub(segtree, lazy, rangelow, rangehigh, low, mid, 2 * pos + 1);

            RangeMinimumQueryLazy_sub(segtree, lazy, rangelow, rangehigh, mid, high, 2 * pos + 2);

            segtree[pos] = min(segtree[2 * pos + 1], segtree[2 * pos + 2]);

            return segtree[pos];
        }

    public:
        void CreateSegmentTree(int input[], int n, int*& segtree, int& length)
        {
            int nextPowOfTwo = (int)ceil(log2(n) + 1);

            length = (int)pow(2, nextPowOfTwo) - 1;

            segtree = new int[length];
            memset(segtree, 0, length * sizeof(int));

            CreateSegmentTree_sub(segtree, input, 0, n - 1, 0);


        }

        int RangeMinimumQuery(int segtree[], int qlow, int qhigh, int n)
        {
            return RangeMinimumQuery_sub(segtree, 0, n - 1, qlow, qhigh, 0);

        }

        void UpdateSegmentTree(int input[], int n, int segtree[], int index, int value)
        {
            input[index] += value;

            UpdateSegmentTree_sub(segtree, index, value, 0, n - 1, 0);
        }

        void UpdateSegmentTreeRange(int input[], int n, int segtree[], int rangelow, int rangehigh, int value)
        {
            for (int i = rangelow; i <= rangehigh; i++)   input[i] += value;

            UpdateSegmentTreeRange_sub(segtree, 0, n - 1, rangelow, rangehigh, 0, value);

        }

        void UpdateSegmentTreeRangeLazy(int input1[], int n, int segtree[], int lazy[], int rangelow, int rangehigh, int value)
        {
            UpdateSegmentTreeRangeLazy_sub(segtree, lazy, rangelow, rangehigh, value, 0, n - 1, 0);
        }

        int RangeMinimumQueryLazy(int segtree[], int lazy[], int rangelow, int rangehigh, int n)
        {
            return RangeMinimumQueryLazy_sub(segtree, lazy, rangelow, rangehigh, 0, n - 1, 0);
        }

        void PrintArray(int arr[], int n)
        {
            for (int i = 0; i < n; i++)   cout << arr[i] << ",";
            cout << endl;
        }
    };
};

int SegTreeLazyPropagatioin_Test()
{
    SegmentTreeMinimumRangeQuery::Solution ob;

    int length = 0;

    int input[] = { 0,3,4,2,1,6,-1 };
    int n = sizeof(input) / sizeof(int);

    int* segTree=nullptr;
    
    ob.CreateSegmentTree(input, n, segTree, length);

    // print output
    ob.PrintArray(segTree, length);

    //non lazy propagation example
    cout << ob.RangeMinimumQuery(segTree, 0, 3, n) << endl;
    cout << ob.RangeMinimumQuery(segTree, 1, 5, n) << endl;
    cout << ob.RangeMinimumQuery(segTree, 1, 6, n) << endl;

    ob.UpdateSegmentTree(input, n, segTree, 2, 1);

    cout << ob.RangeMinimumQuery(segTree, 1, 3, n) << endl;

    ob.UpdateSegmentTreeRange(input, n, segTree, 3, 5, -2);

    cout << ob.RangeMinimumQuery(segTree, 5, 6, n) << endl;

    cout << ob.RangeMinimumQuery(segTree, 0, 3, n) << endl;

    //lazy propagation example

    int input1[] = { -1,2,4,1,7,1,3,2 };

    int n1 = sizeof(input1) / sizeof(int);

    int* segTree1 = nullptr;
    
    ob.CreateSegmentTree(input1, n1, segTree1, length);

    int* lazy = new int[length];

    memset(lazy, 0, length * sizeof(length));

    ob.UpdateSegmentTreeRangeLazy(input1, n, segTree1, lazy, 0, 3, 1);

    ob.UpdateSegmentTreeRangeLazy(input1, n, segTree1, lazy, 0, 0, 2);

    cout << ob.RangeMinimumQueryLazy(segTree1, lazy, 3, 5, n) << endl;

    return 0;
}
