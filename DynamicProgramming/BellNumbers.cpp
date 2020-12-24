//
// https://www.geeksforgeeks.org/bell-numbers-number-of-ways-to-partition-a-set/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace BellNumbers
{
    const int ELEMENTS = 20;

    long long Run(long long n)
    {
        if (n == 0 || n == 1)   return 1;

        long long arr[2][ELEMENTS];

        arr[0][0] = arr[1][0] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                arr[1][j] = arr[1][j - 1] + arr[0][j - 1];
            }

            for (int j = 0; j <= i; j++)
            {
                arr[0][j] = arr[1][j];
                arr[1][j] = 0;
            }
            arr[1][0] = arr[0][i];
        }
            

        return arr[1][0];
    }
};

namespace BellNumbers_Recursive
{
    const int ELEMENTS = 20;
    long long arr[ELEMENTS][ELEMENTS];

    long long Bell(int i, int j)
    {
        if (i == 0 && j == 0)   return 1;

        else if (arr[i][j] != 0)    return arr[i][j];

        else if (j == 0) return Bell(i - 1, i - 1);
        
        else
        {
            long long left = Bell(i, j - 1);
            long long leftTop = Bell(i - 1, j - 1);
            return left + leftTop;
        }
    }
    
    long long Run(int n)
    {
        if (n == 0 || n == 1)   return 1;
        
        for (int i = 0; i < ELEMENTS; i++)
        {
            for (int j = 0; j < ELEMENTS; j++)
            {
                arr[i][j] = 0;
            }
        }
        
        arr[0][0] = arr[1][0] = 1;

        return Bell(n-1, n-1);
    }
};

// Driven Program 
int BellNumbers_Test()
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        cout << BellNumbers_Recursive::Run(n) << endl;
    };

    return 0;

}