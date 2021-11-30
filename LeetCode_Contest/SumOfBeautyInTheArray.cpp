/*
* https://leetcode.com/problems/sum-of-beauty-in-the-array/
* 
* ou are given a 0-indexed integer array nums. For each index i (1 <= i <= nums.length - 2) the beauty of nums[i] equals:

    2, if nums[j] < nums[i] < nums[k], for all 0 <= j < i and for all i < k <= nums.length - 1.
    1, if nums[i - 1] < nums[i] < nums[i + 1], and the previous condition is not satisfied.
    0, if none of the previous conditions holds.

Return the sum of beauty of all nums[i] where 1 <= i <= nums.length - 2.

 

Example 1:

Input: nums = [1,2,3]
Output: 2
Explanation: For each index i in the range 1 <= i <= 1:
- The beauty of nums[1] equals 2.

Example 2:

Input: nums = [2,4,6,4]
Output: 1
Explanation: For each index i in the range 1 <= i <= 2:
*/

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

namespace SumOfBeautyInTheArray
{
    class Solution_LeftAndRightArray
    {
    public:

        int sumOfBeauties(vector<int>& nums)
        {
            int n = nums.size();

            vector<int> left(n);
            vector<int> right(n);

            left[0] = nums[0];
            right[n - 1] = nums[n - 1];

            for (int i = 1; i < n; i++)
            {
                left[i] = max(left[i - 1], nums[i]);
            }
            for (int i = n - 2; i >= 0; i--)
            {
                right[i] = min(nums[i], right[i + 1]);
            }

            int count = 0;

            for (int i = 1; i < n - 1; i++)
            {
                if (left[i - 1] < nums[i] && nums[i] < right[i + 1])
                {
                    count += 2;
                }
                else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                {
                    count++;
                }
            }

            return count;
        }
    };

    class Solution_RightArrayOnly
    {
    public:

        int sumOfBeauties(vector<int>& nums)
        {
            int n = nums.size();

            vector<int> right(n);

            right[n - 1] = nums[n - 1];

            for (int i = n - 2; i >= 0; i--)
            {
                right[i] = min(nums[i], right[i + 1]);
            }

            int count = 0;
            int pre = nums[0];
            for (int i = 1; i < n - 1; i++)
            {
                if (pre < nums[i] && nums[i] < right[i + 1])
                {
                    count += 2;
                }
                else if (nums[i - 1] < nums[i] && nums[i] < nums[i + 1])
                {
                    count++;
                }
                pre = max(pre, nums[i]);
            }

            return count;
        }
    };

};

int SumOfBeautyInTheArray_Test()
{
    vector<int> arr = { 55,36,68,97,1,20,5,50,53,21,15,66,93,12,31,14,13,3,24,97,30,14,28,4,67,86,60,59,40,69,83,49,28,88,98,27,94,56,55,66,3,75,76,7,54,68,75,24,13,85,62,47,3,67,16,79,47,38,89,48,40,3,88,53,13,14,40,26,100,87,3,58,8,53,82,63,60,27,76,79,10,1,37,4,48,40,93,10,29,97 };

    SumOfBeautyInTheArray::Solution_LeftAndRightArray ob;

    cout << ob.sumOfBeauties(arr) << endl;

    SumOfBeautyInTheArray::Solution_RightArrayOnly ob1;

    cout << ob1.sumOfBeauties(arr) << endl;

    
    return 0;
}
