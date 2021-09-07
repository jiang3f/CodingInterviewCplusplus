/*
*  https://www.geeksforgeeks.org/maximum-value-array-m-range-increment-operations/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

namespace MaximumValueInAnArrayAfterMRangeIncrementOperations
{
    class Solution
    {
    public:
        int findMax(int n, int m, int a[], int b[], int k[])
        {
            int* arr = new int[n];
            for (int i = 0; i < n; i++)   arr[i] = 0;

            for (int i = 0; i < m; i++)
            {
                int lowerBound = a[i];
                int uppperBound = b[i];

                arr[lowerBound] += k[i];
                arr[uppperBound + 1] -= k[i];
            }

            int sum = INT_MIN;
            for (int i = 1; i < n; i++)
            {
                arr[i] = arr[i - 1] + arr[i];
                if (arr[i] > sum)   sum = arr[i];
            }

            return sum;
        }
    };

};

int MaximumValueInAnArrayAfterMRangeIncrementOperations_Test()
{
    int n = 5;

    int a[] = { 0, 1, 2 };
    int b[] = { 1, 4, 3 };
    int k[] = { 100, 100, 100 };

    // m is number of operations.
    int m = sizeof(a) / sizeof(a[0]);

    MaximumValueInAnArrayAfterMRangeIncrementOperations::Solution ob;

    cout << "Maximum value after 'm' operations is "
        << ob.findMax(n, m, a, b, k);
    return 0;
    return 0;
}

