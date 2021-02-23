//
// https://practice.geeksforgeeks.org/problems/longest-common-prefix-in-an-array5129/1
/*
*
    Expected Time Complexity: O(N*max(|arri|)).
    Expected Auxiliary Space: O(max(|arri|)) for result.


    Constraints:
    1<=N<=103
    1<=|arri|<=103

*/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace LongestCommonPrefixInAnArray
{
    class Solution 
    {
    public:

        string CommonPrefix(string s1, string s2)
        {
            int i = 0;

            while (i < s1.size() && i < s2.size())
            {
                if (s1.at(i) != s2.at(i))   break;

                i++;
            }

            if (i == 0) return "";
            else            return s1.substr(0, i);
        }

        string longestCommonPrefix(string arr[], int N)
        {
            // your code here
            if (N == 0) return "";

            string ret = arr[0];

            for (int i = 1; i < N; i++)
            {
                ret = CommonPrefix(ret, arr[i]);
                if (ret.empty() == true)    return "";
            }

            return ret;
        }
    };

};

// Driven Program 
// 
int LongestCommonPrefixInAnArray_Test()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string *arr = new string [n];

        for (int i = 0; i < n; ++i)
            cin >> arr[i];

        LongestCommonPrefixInAnArray::Solution ob;
        cout << ob.longestCommonPrefix(arr, n) << endl;
    }

    return 0;
}