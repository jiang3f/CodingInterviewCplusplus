//
//https://www.geeksforgeeks.org/painters-partition-problem/
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// 

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

namespace ThePaintersPartition
{
    string MakeKey(int a1, int a2, int m)
    {
        char buf[250];
        sprintf(buf, "%d,%d,%d", a1, a2, m);
        string s(buf);
        return s;
    }

    long long findPagesSub(int arr[], int n, int a1, int a2, int m, map<string, long long>& dp)
    {
        if (a1 > a2)    return LLONG_MAX;

        if (a1 >= n || a2 >= n)    return LLONG_MAX;
        
        string key = MakeKey(a1, a2, m);

        map<string, long long>::iterator it = dp.find(key);
        if (it != dp.end())
        {
            return it->second;
        }
        else if (m == 1)
        {
            long long ret = 0;
            for (int i = a1; i <= a2; i++)
            {
                ret += arr[i];
            }
            dp[key] = ret;
            return ret;
        }
        else
        {
            long long total = LLONG_MAX;

            for (int k = 1; k < a2 - a1 + 1; k++)
            {
                long long left = findPagesSub(arr, n, a1, k+a1-1, 1, dp);                
                long long right = findPagesSub(arr, n, k+a1, a2, m - 1, dp);
                
                //cout << "left: from " << a1 << " to " << k+a1-1 << " painters: " << 1 << " max units " << left << ";";

                //cout << "right: from " << k+a1 << " to " << a2 << " painters: " << m - 1 << " max unites " << right << endl;

                long long value = (left > right) ? left : right;
                if (value < total)    total = value;
            }
            dp[key] = total;
            return total;
        }

    }

    //User function template in C++

    long long findPages(int arr[], int n, int m)
    {
        //code here
        if (m <= 0) return 0;

        else if (n <= 0 || arr == NULL) return 0;

        else if (m > n) return 0;

        map<string, long long> dp;

        long long ret = findPagesSub(arr, n, 0, n - 1, m, dp);

        return ret;
    }


};

namespace ThePaintersPartition_dp
{
    long long sum(int arr[], int n, int k)
    {
        long long total = 0;
        for (int i = k; i < n; i++)
        {
            total += arr[i];
        }
        return total;
    }

    long long findPages(int arr[], int n, int m)
    {
        if (arr == NULL || n == 0 || m == 0)  return 0;

        if (m == 1)
        {
            return sum(arr, n, 0);
        }

        long long ** dp;
        dp = new long long * [n+1];
        for (int i = 0; i < n+1; i++)
        {
            dp[i] = new long long[m + 1];
        }

        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= m; j++)
            {
                dp[i][j] = 0;
            }
        }

        for (int i = 1; i <= n; i++)
        {
            dp[i][1] = sum(arr, i, 0);
        }

        for (int i = 1; i <= m; i++)
        {
            dp[1][i] = arr[0];
        }

        for (int j = 2; j <= m; j++)
        {
            for (int i = 2; i <= n; i++)
            {
                long long total = INT_MAX;

                for (int k = 1; k < i; k++)
                {
                    long long right = sum(arr, i, k);
                    long long left = dp[k][j-1];

                    long long value = (left > right) ? left : right;
                    if (value < total)    total = value;
                }
                
                dp[i][j] = total;
            }
        }

        return dp[n][m];
    }
};

int ThePaintersPartition_Test()
{
    int arr[] = { 250, 74, 159, 181, 23, 45, 129, 174 };
    cout << ThePaintersPartition_dp::findPages(arr, 8, 6) << endl;
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int* A;
        A = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        int m;
        cin >> m;
        //cout << ThePaintersPartition::findPages(A, n, m) << endl;
        cout << ThePaintersPartition_dp::findPages(A, n, m) << endl;
    }
    
    return 0;
}