//
// https://www.geeksforgeeks.org/permutation-coefficient/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace PermutationCoefficient_recursive
{

    // P(n, k) = P(n-1, k) + k* P(n-1, k-1)   
    int nPr (int n, int k, int **arr)
    {
        if (k == 0) return 1;
        else if (k > n) return 0;
        else if (k == 1)    return n;
        else if (arr[n][k] != 0)    return arr[n][k];
        else
        {
            int ret = nPr(n - 1, k, arr) + k * nPr(n - 1, k - 1, arr);
            arr[n][k] = ret;

            return ret;
        }
    }

    int Run(int n, int k)
    {
        int** dp;

        dp = new int* [n + 1];

        for (int i = 0; i < n + 1; i++)
        {
            dp[i] = new int[k + 1];
        }

        for (int i = 0; i < n + 1; i++)
        {
            for (int j = 0; j < k + 1; j++)
            {
                dp[i][j] = 0;
            }
        }

        return nPr(n, k, dp);
    }

};

namespace PermutationCoefficient
{
    int Run(int n, int r)
    {
        int** arr;
        arr = new int* [n + 1];

        for (int i = 0; i < n + 1; i++)
        {
            arr[i] = new int[r + 1];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= std::min(r, i); j++)
            {
                if (j == 0) arr[i][j] = 1;

                else
                    arr[i][j] = arr[i - 1][j] + (j * arr[i - 1][j - 1]);

                arr[i][j + 1] = 0;
            }

        }

        return arr[n][r];
    }
};

// Driven Program 
// 
int PermutationCoefficient_Test()   
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        int n, r;
        cin >> n >> r;
        cout << PermutationCoefficient::Run (n, r) << endl;
    };

    return 0;

}