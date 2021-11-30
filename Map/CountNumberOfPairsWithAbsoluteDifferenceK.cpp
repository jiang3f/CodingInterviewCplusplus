/*
* https://leetcode.com/contest/biweekly-contest-61/problems/count-number-of-pairs-with-absolute-difference-k/

Given an integer array nums and an integer k, return the number of pairs (i, j) where i < j such that |nums[i] - nums[j]| == k.

The value of |x| is defined as:

    x if x >= 0.
    -x if x < 0

Input: nums = [1,2,2,1], k = 1
Output: 4
Explanation: The pairs with an absolute difference of 1 are:
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]
- [1,2,2,1]


Constraints:

    1 <= nums.length <= 200
    1 <= nums[i] <= 100                                             /// important information
    1 <= k <= 99

*/


#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

namespace CountNumberOfPairsWithAbsoluteDifferenceK
{
    class Solution_TwoLoop
    {
    public:
        int countKDifference(vector<int>& nums, int k) 
        {
            int ret = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                for (int j = i + 1; j < nums.size(); j++)
                {
                    if (nums[i] == (nums[j] + k) || (nums[i] + k) == nums[j])   ret++;
                }
            }

            return ret;
        }
    };

    class Solution_Map {
    public:
        int countKDifference(vector<int>& nums, int k) 
        {
            unordered_map<int, int> myMap;
            int ret = 0;

            for (int i = 0; i < nums.size(); i++)
            {

                // nums[i] + k == nums[x]
                if ((nums[i] + k) <= 100)
                {
                    ret += myMap[nums[i] + k];
                }

                // nums[i] = nums[x] + k;
                if ((nums[i] - k) >= 1)
                {
                    ret += myMap[nums[i] - k];
                }
                myMap[nums[i]] ++;

            }
            return ret;
        }
    };
};

int CountNumberOfPairsWithAbsoluteDifferenceK_Test()
{
    vector<int> arr = { 3,2,1,5,4 };
    int k = 2;

    CountNumberOfPairsWithAbsoluteDifferenceK::Solution_TwoLoop ob;

    cout << ob.countKDifference(arr, k) << endl;

    CountNumberOfPairsWithAbsoluteDifferenceK::Solution_Map ob1;

    cout << ob1.countKDifference(arr, k) << endl;

    return 0;
}
