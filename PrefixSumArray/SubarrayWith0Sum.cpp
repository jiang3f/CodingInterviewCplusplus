/*
* https://www.geeksforgeeks.org/find-subarray-with-given-sum/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

namespace SubarrayWith0Sum
{
    class Solution {
    public:
        //Complete this function
        //Function to check whether there is a subarray present with 0-sum or not.
        bool subArrayExists(int arr[], int n)
        {
            //Your code here
            vector<int> prefixSum;
            prefixSum.push_back(arr[0]);

            for (int i = 1; i < n; i++)
            {
                int v = prefixSum[i - 1] + arr[i];
                if (v == 0) return true;
                if (find(prefixSum.begin(), prefixSum.end(), v) != prefixSum.end())    return true;
                prefixSum.push_back(v);

            }
            if (prefixSum[n - 1] == 0)    return true;

            return false;
        }
    };

    class Solution_set
    {
    public:
        bool subArrayExists(int arr[], int n)
        {
            unordered_set<int> sumSet;

            // Traverse through array
            // and store prefix sums
            int sum = 0;
            for (int i = 0; i < n; i++)
            {
                sum += arr[i];

                // If prefix sum is 0 or
                // it is already present
                if (sum == 0
                    || sumSet.find(sum)
                    != sumSet.end())
                    return true;

                sumSet.insert(sum);
            }
            return false;
        }
    };
};

int SubarrayWith0Sum_Test()
{
    int a[] = { 4 ,2 ,-3, 1 ,6 };

    SubarrayWith0Sum::Solution_set ob;

    cout << ob.subArrayExists(a, sizeof(a) / sizeof(a[0])) << endl;
    return 0;

}