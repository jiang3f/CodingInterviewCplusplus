/*
* https://www.geeksforgeeks.org/random-number-generator-in-arbitrary-probability-distribution-fashion/
*/

#include "stdafx.h"
#include <iostream>
#include <time.h>

using namespace std;

namespace RandomNumberGenerator
{
    class Solution
    {
    private:
        int FindCeil(int prefix[], int number, int left, int right)
        {
            int mid;
            while (left < right)
            {
                mid = left + ((right - left) >> 1);
                (number > prefix[mid]) ? left = mid + 1 : right = mid;
            }

            return (prefix[left] >= prefix[right]) ? left : -1;
        }

    public:
        int myRand(int arr[], int freqp[], int n)
        {
            int* prefixSum = new int[n];

            prefixSum[0] = freqp[0];

            for (int i = 1; i < n; i++)
            {
                prefixSum[i] = prefixSum[i - 1] + freqp[i];
            }

            // prefix[n-1] is sum of all frequencies.
            // Generate a random number with
            // value from 1 to this sum
            int r = (rand() % prefixSum[n - 1]) + 1;

            int index = FindCeil(prefixSum, r, 0, n - 1);

            return arr[index];
        };
    };
};

int RandomNumberGenerator_Test()
{
    int arr[] = { 1, 2, 3, 4 };
    int freq[] = { 10, 5, 20, 100 };
    int i, n = sizeof(arr) / sizeof(arr[0]);

    // Use a different seed value for every run.
    srand(time(NULL));

    RandomNumberGenerator::Solution ob;

    // Let us generate 10 random numbers accroding to
    // given distribution
    for (i = 0; i < 5; i++)
        cout << ob.myRand(arr, freq, n) << endl;

    return 0;
}

