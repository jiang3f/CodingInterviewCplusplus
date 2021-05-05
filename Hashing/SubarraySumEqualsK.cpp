/*
* https://leetcode.com/discuss/interview-question/algorithms/124820/continuous-sequence-against-target-number
* 
*  facebook screening interview question 
*/

#include "stdafx.h"
#include <iostream>
#include <unordered_set>

using namespace std;

namespace SubarraySumEqualsK
{
    bool consecutiveSum(int nums[], int n, int k)
    {
        if (nums == nullptr || n == 0)
        {
            return false;
        }

        unordered_set<int> set;

        int sum = 0;
        int diff = 0;

        for (int i = 0; i < n; i++)
        {

            sum += nums[i];
            if (sum == k) {
                return true;
            }
            diff = sum - k;

            if (set.find(diff) != set.end())
            {
                return true;
            }
            else {

                set.insert(sum);
            }
        }

        return false;
    }
};

int SubarraySumEqualsK_Test()
{
    int arr[] = { 23, 5, 4, 7, 2, 11 };
    int k = 20;

    bool ret = SubarraySumEqualsK::consecutiveSum(arr, sizeof(arr) / sizeof(arr[0]), k);

    if (ret)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}