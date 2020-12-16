//
// https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace CatalanNumber
{
    long long factor(int n)
    {
        long long ret = 1;

        for (int i = n; i >= 1; i--)
        {
            ret = ret * i;
        }

        return ret;
    }

    long long factor1(int n1, int n2)
    {
        long long ret = 1;

        for (int i = n1; i >= n2; i--)
        {
            ret = ret * i;
        }

        return ret;
    }

    long long Run(long long n)
    {
        long long ret = factor1(n * 2, n);
        ret = ret / factor(n);
        ret = ret / (n + 1);

        return ret;
    }
};

namespace CatalanNumber_Series
{
    //
    unsigned long long int Catalan (int n, unsigned long long int dp[])
    {
        if (n == 0) return 1;

        if (dp[n] != 0) return dp[n];

        unsigned long long int ret = 0;

        for (int i = 0; i < n; i++)
        {
            unsigned long long int ci = Catalan(i, dp);

            unsigned long long int cni = Catalan(n - i - 1, dp);

            ret += ci * cni;
        }

        dp[n] = ret;

        return ret;
    }

    unsigned long long int Run(int n)
    {
        if (n > 40)
        {
            cout << "standard c++ doesn't support long range integer number, consider install boost" << endl;
            return 0;
        }

        unsigned long long int dp[101];

        for (int i = 0; i < 101; i++)
        {
            dp[i] = 0;
        }

        return Catalan (n, dp);

    }
};


// Driven Program 
int CatalanNumber_Test()
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << CatalanNumber_Series::Run(n) << endl;
    };

    return 0;

}