/*
* https://leetcode.com/problems/minimum-incompatibility/
*/

/*
* You are given an integer array nums??? and an integer k. You are asked to distribute this array into k subsets of equal size such that there are no two equal elements in the same subset.

A subset's incompatibility is the difference between the maximum and minimum elements in that array.

Return the minimum possible sum of incompatibilities of the k subsets after distributing the array optimally, or return -1 if it is not possible.

A subset is a group integers that appear in the array with no particular order.
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
namespace MinimumIncompatibility
{
    class Solution {
    public:
        void PrintAllSubsets(vector<vector<int>>& output, int& minINC)
        {
            int sum = 0;

            for (int i = 0; i < output.size(); i++)
            {
                sort(output[i].begin(), output[i].end());

                /*int j = 0;
                for (j = 0; j < output[i].size(); j++)
                {
                    cout << output[i][j] << " ";
                }
                cout << endl;
                */
                sum += output[i][output[i].size() - 1] - output[i][0];
            }


            //cout << "sum = " << sum << endl;

            if (sum < minINC)   minINC = sum;
        }

        //find all combinations
        bool minimumIncompatibility_Sub(vector<vector<int>> output, vector<int>& nums, int k, int size, int& minINC)
        {
            if (nums.empty())
            {
                PrintAllSubsets(output, minINC);
                return true;
            }

            for (int i = 0; i < k; i++)
            {
                if (output[i].size() < size)
                {
                    if (find(output[i].begin(), output[i].end(), nums[0]) == output[i].end())
                    {
                        vector<vector<int>> output1(output.begin(), output.end());
                        output1[i].push_back(nums[0]);

                        vector<int> newNums(nums.begin() + 1, nums.end());
                        minimumIncompatibility_Sub(output1, newNums, k, size, minINC);
                    }
                }
            }

            return true;
        }

        int minimumIncompatibility(vector<int>& nums, int k)
        {
            vector<vector<int>> output;
            for (int i = 0; i < k; i++)
            {
                vector<int> subset;
                output.push_back(subset);
            }
            int size = nums.size() / k;

            output[0].push_back(nums[0]);

            vector<int> newNums(nums.begin() + 1, nums.end());

            int minINC = INT_MAX;

            minimumIncompatibility_Sub(output, newNums, k, size, minINC);

            return minINC;
        }
    };


};

int MinimumIncompatibility_Test()
{
    vector<int> nums = { 1, 2, 1, 4 };
    int k = 2;

    MinimumIncompatibility::Solution ob;

    ob.minimumIncompatibility(nums, k);

    return 0;
}

