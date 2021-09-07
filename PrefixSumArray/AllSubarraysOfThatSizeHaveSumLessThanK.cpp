/*
* https://www.geeksforgeeks.org/maximum-subarray-size-subarrays-size-sum-less-k/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

namespace AllSubarraysOfThatSizeHaveSumLessThanK
{
    class Solution_BinarySearch // O(nlogn)
    {
    public:
        bool IsSumLess(int prefix_sum[], int n, int k, int size)
        {
            int ret = true;

            cout << "Sum of subarrays of " << size << ":";
            for (int i = 0; i <= n - size;i ++)
            {
                cout << prefix_sum[i + size] - prefix_sum[i] << " ";

                if ((prefix_sum[i + size] - prefix_sum[i]) > k)   ret = false;
            }

            cout << endl;

            return ret;
        }

        int MaxSize(int arr[], int n, int k)
        {
            int ans = -1;

            // generate prefix sum array
            int* prefix_sum = new int[n+1];

            prefix_sum[0] = 0;
            prefix_sum[1] = arr[0];
            
            for (int i = 1; i < n; i++)
            {
                prefix_sum[i+1] = prefix_sum[i] + arr[i];
            }

            int start = 0;
            int end = n;

            while (start < end)
            {
                int mid = (start + end) / 2;

                if (IsSumLess(prefix_sum, n, k, mid) == true)
                {
                    if (ans < mid)
                    {
                        ans = mid;
                    }
                    start = mid+1;
                }
                else
                {
                    end = mid-1;
                }
            }
            return ans;
        }
    };

    class Solution_SlidingWindow
    {
    public:
        int MaxSize(int arr[], int n, int k)
        {
            int ans = n;
            int sum = 0;
            int left = 0, right;

            for (right = 0;right < n;right ++)
            {
                sum += arr[right];

                while (sum > k)
                {
                    sum -= arr[left];
                    left++;
                    ans = min(ans, right - left + 1);
                }


                if (sum == 0)
                {
                    ans = -1;
                    break;
                }
            }

            return ans;
        }
    };

};

int AllSubarraysOfThatSizeHaveSumLessThanK_Test()
{
    int arr[] = { 1, 2, 10, 4 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 14;

    AllSubarraysOfThatSizeHaveSumLessThanK::Solution_SlidingWindow ob;

    cout << ob.MaxSize(arr, n, k) << endl;
    return 0;
}