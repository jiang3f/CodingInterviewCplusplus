//
// https://practice.geeksforgeeks.org/problems/pairs-of-prime-number2612/1
// 

/*
* 
xpected Time Complexity: O(n2* sqrt(n))
Expected Space Complexity: O(1)
 * */

#include "stdafx.h"
#include <iostream>
#include <strstream>
#include <vector>
#include <algorithm>

using namespace std;
namespace PairsOfPrimeNumber
{
    string mkkey(int a, int b)
    {
        ostrstream ss;
        ss << a << "," << b << ends;
        return ss.str();
    }

    vector<string> Run(int n)
    {
        int* primes = new int[n];
        int primesNum = 1;
        primes[0] = 2;

        for (int v = 3; v < n/2; v++)
        {
            int root = sqrt(v);

            int j = 0;
            for (j = 0; j < root; j++)
            {
                if ((v % primes[j]) == 0) break;
            }

            if (j == root)
            {
                primes[primesNum] = v;
                primesNum++;
            }
        }

        for (int i = 0; i < primesNum; i++)
        {
            cout << primes[i] << " ";
        }
        cout << endl;

        vector<string> set;

        int left = 0;
        int right = primesNum;

        while (left <= right)
        {
            int value = primes[left] * primes[right];
            if (value < n)  right--;

            for (int j = left; j <= right; j++)
            {
                string key = mkkey(primes[left], primes[j]);

                if (find(set.begin(), set.end(), key) == set.end())
                {
                    set.push_back(key);
                }
            }
        }

        return set;
    }

};

int PairsOfPrimeNumberint_Test()
{
    /*
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)   cin >> arr[i];
        int m;
        cin >> m;
        //cout << WordWrap_Memoization::Run(arr, n, m) << "\n";
        WordWrap_Tabulation::solveWordWrap(arr, n, m);
        cout << endl;

    }*/

    int n = 8;

    vector<string> ret = PairsOfPrimeNumber::Run(n);

    for (int i = 0; i < ret.size(); i++)
    {
        cout << ret[i] << endl;
    }

    return 0;
}