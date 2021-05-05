//
//https://www.geeksforgeeks.org/word-wrap-problem-dp-19/
// https://practice.geeksforgeeks.org/problems/word-wrap/0
// 

/*
The idea is to have balanced lines. In other words, not have few lines with lots of extra spaces and some lines with small amount of extra spaces.

The extra spaces includes spaces put at the end of every line except the last one.  
The problem is to minimize the following total cost.

    Cost of a line = (Number of extra spaces in the line)^3
    Total Cost = Sum of costs for all lines

 * */

#include "stdafx.h"
#include <iostream>
#include <map>
#include <strstream>

using namespace std;
namespace WordWrap_Memoization
{
    string MakeKey(int i, int j)
    {
        strstream ss;
        ss << i << "," << j << ends;
        return ss.str();
    }

    pair<int, int> MinWordWrap(int arr[], int a1, int a2, int lineWidth, map<string, pair<int,int>>& dp)
    {
        string key = MakeKey(a1, a2);
        
        if (dp.find(key) != dp.end())
        {
            return dp[key];
        }
        else if (a1 == a2)
        {
            dp[key].first = 0;
            dp[key].second = lineWidth - arr[a1];

            cout << key << "=(" << dp[key].first << "," << dp[key].second << ")" << endl;

            return dp[key];
        }
        else
        {
            int sum = 0;

            for (int n = a1; n <= a2; n++)
            {
                sum += arr[n];
            }
            sum += a2 - a1;

            if (sum <= lineWidth)
            {
                dp[key].first = 0;

                dp[key].second = lineWidth - sum;
                
                cout << key << "=(" << dp[key].first << "," << dp[key].second << ")" << endl;

                return dp[key];
            }
            else
            {
                int ret = INT_MAX;
                int extra = 0;
                for (int ln = 1; ln <= a2 - a1; ln++)
                {
                    int i = a1 + ln;
                    pair<int, int> left = MinWordWrap(arr, a1, i-1, lineWidth, dp);
                    pair<int, int> right = MinWordWrap(arr, i, a2, lineWidth, dp);

                    int extra1 = left.second * left.second * left.second;

                    int m = left.first + right.first + extra1;

                    if (m < ret)
                    {
                        ret = m;
                        extra = right.second;
                    }
                }

                dp[key].first = ret;
                dp[key].second = extra;

                cout << key << "=(" << dp[key].first << "," << dp[key].second << ")" << endl;

                return dp[key];
            }
        }
    }

    int Run(int arr[], int n, int width)
    {
        map<string, pair<int, int>> dp;

        //int ret = MinWordWrap(arr, 0, n - 1, width, dp);
        pair<int, int> ret = MinWordWrap(arr, 0, n-1, width, dp);
        
        int extra = ret.second * ret.second * ret.second;
        return ret.first + extra ;
    }

};

namespace WordWrap_Tabulation
{
#define INF INT_MAX  
    
    // A Dynamic programming solution for Word Wrap Problem  

    // A utility function to print the solution  
    int printSolution(int p[], int n);

    // l[] represents lengths of different words in input sequence.  
    // For example, l[] = {3, 2, 2, 5} is for a sentence like  
    // "aaa bb cc ddddd". n is size of l[] and M is line width  
    // (maximum no. of characters that can fit in a line)  
    void solveWordWrap(int l[], int n, int M)
    {
        // For simplicity, 1 extra space is used in all below arrays  

        // extras[i][j] will have number of extra spaces if words from i  
        // to j are put in a single line  
        int** extras;
        extras = new int* [n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            extras[i] = new int[n + 1];
        }

        // lc[i][j] will have cost of a line which has words from  
        // i to j  
        int** lc;
        lc = new int* [n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            lc[i] = new int[n + 1];
        }


        // c[i] will have total cost of optimal arrangement of words  
        // from 1 to i  
        int* c = new int [n + 1] ;


        // p[] is used to print the solution.  
        int *p = new int [n + 1];

        int i, j;

        // calculate extra spaces in a single line. The value extra[i][j]  
        // indicates extra spaces if words from word number i to j are  
        // placed in a single line  
        for (i = 1; i <= n; i++)
        {
            extras[i][i] = M - l[i - 1];
            for (j = i + 1; j <= n; j++)
                extras[i][j] = extras[i][j - 1] - l[j - 1] - 1;
        }

        // Calculate line cost corresponding to the above calculated extra  
        // spaces. The value lc[i][j] indicates cost of putting words from  
        // word number i to j in a single line  
        for (i = 1; i <= n; i++)
        {
            for (j = i; j <= n; j++)
            {
                if (extras[i][j] < 0)
                    lc[i][j] = INF;
                else if (j == n && extras[i][j] >= 0)
                    lc[i][j] = 0;
                else
                    lc[i][j] = extras[i][j] * extras[i][j];
            }
        }

        // Calculate minimum cost and find minimum cost arrangement.  
        // The value c[j] indicates optimized cost to arrange words  
        // from word number 1 to j.  
        c[0] = 0;
        for (j = 1; j <= n; j++)
        {
            c[j] = INF;
            for (i = 1; i <= j; i++)
            {
                if (c[i - 1] != INF && lc[i][j] != INF &&
                    (c[i - 1] + lc[i][j] < c[j]))
                {
                    c[j] = c[i - 1] + lc[i][j];
                    p[j] = i;
                }
            }
        }

        printSolution(p, n);
    }

    int printSolution(int p[], int n)
    {
        int k;
        if (p[n] == 1)
            k = 1;
        else
            k = printSolution(p, p[n] - 1) + 1;
        cout << "Line number " << k << ": From word no. " << p[n] << " to " << n << endl;
        cout << p[n] << " " << n << " ";
        return k;
    }

};


// Driven Program 
int WordWrap_Test ()
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

    int arr[] = { 3, 2, 2, 5 };
    int m = 6;

    WordWrap_Memoization::Run(arr, 4, m);

    return 0;
}