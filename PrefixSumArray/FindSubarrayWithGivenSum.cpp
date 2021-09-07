/*
* https://www.geeksforgeeks.org/find-subarray-with-given-sum-in-array-of-integers/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

namespace FindSubarrayWithGivenSum
{
    class Solution
    {
    public:
        void subArraySum(int arr[], int n, int sum)
        {
            int cur_sum = 0;

            unordered_map<int, int> myMap;

            for (int i = 0; i < n; i++)
            {
                cur_sum += arr[i];

                if (cur_sum == sum)
                {
                    cout << "Sum found between indexes 0 to " << i  << endl;
                    return;
                }

                if (myMap.find(cur_sum - sum) != myMap.end())
                {
                    cout << "Sum found between indexes " << myMap[cur_sum - sum] << " to " << i << endl;
                    return;
                }

                myMap[cur_sum] = i;
            }
        }
    };
};

int FindSubarrayWithGivenSum_Test()
{
    int arr[] = { 10, 2, -2, -20, 10 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = -10;

    FindSubarrayWithGivenSum::Solution ob;

    ob.subArraySum(arr, n, sum);

    return 0;
}
