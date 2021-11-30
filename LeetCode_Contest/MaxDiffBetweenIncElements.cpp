/*
* https://leetcode.com/contest/weekly-contest-260/problems/maximum-difference-between-increasing-elements/ 
*/


/*


Given a 0-indexed integer array nums of size n, find the maximum difference between nums[i] and nums[j] (i.e., nums[j] - nums[i]), such that 0 <= i < j < n and nums[i] < nums[j].

Return the maximum difference. If no such i and j exists, return -1.



Example 1:

Input: nums = [7,1,5,4]
Output: 4
Explanation:
The maximum difference occurs with i = 1 and j = 2, nums[j] - nums[i] = 5 - 1 = 4.
Note that with i = 1 and j = 0, the difference nums[j] - nums[i] = 7 - 1 = 6, but i > j, so it is not valid.

Example 2:

Input: nums = [9,4,3,2]
Output: -1
Explanation:
There is no i and j such that i < j and nums[i] < nums[j].

Example 3:

Input: nums = [1,5,2,10]
Output: 9
Explanation:
The maximum difference occurs with i = 0 and j = 3, nums[j] - nums[i] = 10 - 1 = 9.



Constraints:

    n == nums.length
    2 <= n <= 1000
    1 <= nums[i] <= 109


*/

// 

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace MaxDiffBetweenIncElements
{
    class Solution
    {
    public:
        int maximumDifference(vector<int>& nums)
        {
            int min = INT_MAX;
            int max = INT_MIN;
            int ret = -1, diff = -1;

            for (int i = 0; i < nums.size(); i++)
            {
                int cur = nums[i];

                if (cur < min)
                {
                    min = cur;
                    diff = -1;
                }

                else if (cur > min && (cur - min) > diff)    diff = cur - min;

                if (ret < diff) ret = diff;

                cout << "min=" << min << ", cur=" << cur << ", ret=" << ret << endl;
            }

            return ret;

        }
    };

    // https://leetcode.com/problems/maximum-difference-between-increasing-elements/discuss/1491938/C%2B%2B-easy-solution
    class Solution_discussion
    {
    public:
        int maximumDifference(vector<int>& nums) 
        {
            int max_ = 0, min_p = INT_MAX;

            for (int i = 0; i < nums.size(); i++) 
            {
                min_p = min(min_p, nums[i]);
                max_ = max(max_, nums[i] - min_p);
            }
            return max_ == 0 ? -1 : max_;
        }
    };
};

int MaxDiffBetweenIncElements_Test()
{
    vector<int> nums = {999,997,980,976,948,940,938,928,924,917,907,907,881,878,864,862,859,857,848,840,824,824,824,805,802,798,788,777,775,766,755,748,735,732,727,705,700,697,693,679,676,644,634,624,599,596,588,583,562,558,553,539,537,536,509,491,485,483,454,449,438,425,403,368,345,327,287,285,270,263,255,248,235,234,224,221,201,189,187,183,179,168,155,153,150,144,107,102,102,87,80,57,55,49,48,45,26,26,23,15};

    MaxDiffBetweenIncElements::Solution_discussion ob;

    cout << ob.maximumDifference(nums) << endl;

    return 0;
}


