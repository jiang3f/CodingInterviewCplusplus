//
// https://practice.geeksforgeeks.org/problems/three-way-partitioning/1
// 

/*
* 
* //// BAD QUESTION

Given an array of size n and a range [a, b]. The task is to partition the array around the range such that array is divided into three parts.
1) All elements smaller than a come first.
2) All elements in range a to b come next.
3) All elements greater than b appear in the end.
The individual elements of three sets can appear in any order. You are required to return the modified array.*
*
Expected Time Complexity: O(1)
Expected Auxiliary Space: O(1)
 * */

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>


using namespace std;
namespace ThreeWayPartitioning
{
    class Solution {
    public:
        //Function to partition the array around the range such 
        //that array is divided into three parts.
        void threeWayPartition(vector<int>& array, int a, int b)
        {
            // code here 
            int n = array.size();

            int* arr = new int[n * 3];
            int offset = 0;
            int offsetA = n;
            int offsetB = n * 2;

            for (int i = 0; i < n; i++)
            {
                if (array[i] < a)
                {
                    arr[offset] = array[i];
                    offset++;
                }
                else if (array[i] >= a && array[i] < b)
                {
                    arr[offsetA] = array[i];
                    offsetA++;
                }
                else
                {
                    arr[offsetB] = array[i];
                    offsetB++;
                }
            }

            for (int i = 0; i < offset; i++)
            {
                array[i] = arr[i];
            }
            for (int i = 0; i < offsetA; i++)
            {
                array[i + offset] = arr[i + n];
            }
            for (int i = 0; i < offsetB; i++)
            {
                array[i + offset + offsetA] = arr[i + n * 2];
            }
        }
    };
};

int ThreeWayPartitioning_Test()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;

        vector<int> array(N);
        unordered_map<int, int> ump;

        for (int i = 0; i < N; i++) {
            cin >> array[i];
            ump[array[i]]++;
        }

        int a, b;
        cin >> a >> b;

        vector<int> original = array;

        int k1 = 0, k2 = 0, k3 = 0;
        int kk1 = 0; int kk2 = 0; int kk3 = 0;

        for (int i = 0; i < N; i++)
        {
            if (original[i] > b)
                k3++;
            else if (original[i] <= b and original[i] >= a)
                k2++;
            else if (original[i] < b)
                k1++;
        }

        ThreeWayPartitioning::Solution ob;
        ob.threeWayPartition(array, a, b);

        for (int i = 0; i < k1; i++)
        {
            if (array[i] < b)
                kk1++;
        }

        for (int i = k1; i < k1 + k2; i++)
        {
            if (array[i] <= b and array[i] >= a)
                kk2++;

        }

        for (int i = k1 + k2; i < k1 + k2 + k3; i++)
        {
            if (array[i] > b)
                kk3++;
        }
        bool ok = 0;
        if (k1 == kk1 and k2 == kk2 and k3 == kk3)
            ok = 1;

        for (int i = 0; i < array.size(); i++)
            ump[array[i]]--;

        for (int i = 0; i < array.size(); i++)
            if (ump[array[i]] != 0)
                ok = 0;

        if (ok)
            cout << 1 << endl;
        else
            cout << 0 << endl;

    }

    return 0;
}

