/*
* https://www.geeksforgeeks.org/equilibrium-index-of-an-array/
* https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace EquilibriumIndexOfAnArray
{
    class Solution 
    {
    public:
        void fillPrefixSum(long long arr[], int n, long long prefixSum[])
        {
            prefixSum[0] = arr[0];

            // Adding present element
            // with previous element
            for (int i = 1; i < n; i++)
                prefixSum[i] = prefixSum[i - 1] + arr[i];
        }

        // Function to find equilibrium point in the array.
        // a: input array
        // n: size of array
        int equilibriumPoint(long long a[], int n) {

            // Your code here
            long long* prefixSum1 = new long long[n];
            long long* prefixSum2 = new long long[n];

            prefixSum1[0] = a[0];

            for (int i = 1; i < n; i++)
            {
                prefixSum1[i] = prefixSum1[i - 1] + a[i];
            }

            prefixSum2[n - 1] = a[n - 1];

            for (int i = n - 2; i >= 0; i--)
            {
                prefixSum2[i] = prefixSum2[i + 1] + a[i];
            }

            for (int i = 0; i < n; i++)
            {
                if (prefixSum1[i] == prefixSum2[i]) return i;
            }

            return -1;
        }

    };

    class Solution_BF
    {
    public:
        int equilibriumPoint(long long arr[], int n)
        {
            int i, j;
            long long leftsum, rightsum;

            /* Check for indexes one by one until
            an equilibrium index is found */
            for (i = 0; i < n; ++i)
            {

                /* get left sum */
                leftsum = 0;
                for (j = 0; j < i; j++)
                    leftsum += arr[j];

                /* get right sum */
                rightsum = 0;
                for (j = i + 1; j < n; j++)
                    rightsum += arr[j];

                /* if leftsum and rightsum
                are same, then we are done */
                if (leftsum == rightsum)
                    return i;
            }

            /* return -1 if no equilibrium
            index is found */
            return -1;
        }
    };

    class Solution_2
    {
        int equilibriumPoint(long long arr[], int n)
        {
            long long sum = 0; // initialize sum of whole array
            long long leftsum = 0; // initialize leftsum

            /* Find sum of the whole array */
            for (int i = 0; i < n; ++i)
                sum += arr[i];

            for (int i = 0; i < n; ++i)
            {
                sum -= arr[i]; // sum is now right sum for index i

                if (leftsum == sum)
                    return i;

                leftsum += arr[i];
            }

            /* If no equilibrium index found, then return 0 */
            return -1;
        }
    };

}

int EquilibriumIndexOfAnArray_Test()
{
    /*
    long long t;

    //taking testcases
    cin >> t;

    while (t--) {
        long long n;

        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }

        EquilibriumIndexOfAnArray::Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    */

    long long a[] = { 4,42,27,16,28,3,4,5,9,3,31,5,5,29,10,18,35,35,33,19,41,23,8,32,9,5,8,18,35,13,6,7,6,10,11,13,37,2,25,7,28,43};

    EquilibriumIndexOfAnArray::Solution ob;

    cout << ob.equilibriumPoint(a, sizeof(a) / sizeof(a[0])) << endl;
    return 0;
}
