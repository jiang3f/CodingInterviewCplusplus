/*
* https://www.geeksforgeeks.org/find-prime-number-can-written-sum-consecutive-primes/
*/

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <vector>

using namespace std;

namespace SumOfMostConsecutivePrimesSmallerThanLimit
{
    class Solution
    {
    public:
        void GeneratePrimes(int n, vector<int>& primes)
        {
            int sz = sqrt(n);
            bool * mask = new bool [n+1];
            for (int i = 0; i < n+1; i++)   mask[i] = true;
            mask[2] = true;
            for (int i = 2; i < n; i++)
            {
                if (mask[i] == true)
                {
                    primes.push_back(i);
                }

                for (int j = i; j < n; j += i)
                {
                    mask[j] = false;
                }
            }
        }

        // https://en.wikipedia.org/wiki/Sieve_of_Sundaram
        // an odd number is excluded if it has a non-trivial odd facto

        void SieveOfSundaram(int n, vector<int> &primes)
        {
            int newN = (n - 1) / 2;

            bool* mask = new bool[newN + 1];
            
            for (int i = 0; i <= newN; i++)   mask[i] = false;

            for (int i = 1; i < newN; i++)
            {
                for (int j = i; (i + j + 2 * i * j) < newN; j++)
                {
                    mask[i + j + 2 * i * j] = true;
                }
            }

            primes.push_back(2);

            for (int i = 1; i < newN; i++)
            {
                if (mask[i] == false)
                {
                    primes.push_back(2 * i + 1);
                }
            }
        }

        // Returns the prime number that can written as sum
        // of longest chain of consecutive primes.
        
        void LSCP(int arr[], int n)
        {
            vector<int> primes;
            SieveOfSundaram(10000, primes);

            vector<long long> prefix_sum;
            prefix_sum.push_back(primes[0]);

            for (int i = 1; i < primes.size(); i++)
            {
                prefix_sum.push_back(prefix_sum[i - 1] + primes[i]);
            }


            
        }
    };
};

int SumOfMostConsecutivePrimesSmallerThanLimit_Test()
{
    int arr[] = { 10, 30, 40, 50, 1000 };
    int n = sizeof(arr) / sizeof(arr[0]);

    SumOfMostConsecutivePrimesSmallerThanLimit::Solution ob;

    ob.LSCP(arr, n);
    return 0;
}