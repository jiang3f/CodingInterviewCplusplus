//
// https://practice.geeksforgeeks.org/problems/largest-number-formed-from-an-array1117/1
/*
*
    Expected Time Complexity: O(NlogN)
    Expected Auxiliary Space: O(1)

    Constraints:
    1 <= N <= 105
    0 <= Arr[i] <= 1018
*/
//

#include "stdafx.h"
#include <vector>
#include <iostream>

using namespace std;

namespace LargestNumberFormedFromAnArray
{
    class Solution {
    public:

        bool IsGreater(string s1, string s2)
        {
            int i = 0;
            while (i < s1.size() && i < s2.size())
            {
                if (s1.at(i) > s2.at(i))    return true;
                else if (s1.at(i) < s2.at(i))    return false;
            }

            int m = 0;
            int n = i;
            while (n < s1.size())
            {
                if (s1.at(n) > s1.at(m))    return true;
                else if (s1.at(n) < s1.at(m))   return false;
                n++;
                m++;
            }

            m = 0;
            n = i;
            while(n < s2.size())
            {
                if (s1.at(n) > s1.at(m))    return true;
                else if (s1.at(n) < s1.at(m))   return false;
                n++;
                m++;
            }

            return true;
        }

        void Merge(vector<string>& arr, int start, int mid, int end)
        {
            vector<string> ret;

            int i = start;
            int j = mid;

            while (i < mid && j < end)
            {
                if (IsGreater(arr[i], arr[j]))
                {
                    ret.push_back(arr[i]);
                    i++;
                }
                else
                {
                    ret.push_back(arr[j]);
                    i++;
                }
            }

            while (i < mid)
            {
                ret.push_back(arr[i]);
                i++;
            }
            while (j < end)
            {
                ret.push_back(arr[j]);
                j++;
            }

            arr.clear();
            for (int i = 0; i < ret.size(); i++)
            {
                arr.push_back(ret[i]);
            }
        }

        void MergeSort(vector<string>& arr, int start, int end)
        {
            int mid = (end - start + 1) / 2;

            MergeSort(arr, start, mid);
            MergeSort(arr, mid, end);

            Merge(arr, start, mid, end);

        }

        // The main function that returns the arrangement with the largest value as
        // string.
        // The function accepts a vector of strings
        string printLargest(vector<string>& arr)
        {
            // code here
            if (arr.size() == 0)    return "";

            else if (arr.size() == 1)   return arr[0];

            MergeSort(arr, 0, arr.size());

            string ret;

            for (int i = 0; i < arr.size(); i++)
            {
                ret += arr[i];
            }

            return ret;
        }
    };
};

// Driven Program 
// 
int LargestNumberFormedFromAnArray_Test()
{
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<string> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        LargestNumberFormedFromAnArray::Solution ob;
        auto ans = ob.printLargest(arr);
        cout << ans << "\n";
    }
    return 0;
}