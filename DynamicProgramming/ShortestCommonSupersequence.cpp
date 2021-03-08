//
// https://practice.geeksforgeeks.org/problems/shortest-common-supersequence0322/1
// https://www.geeksforgeeks.org/print-shortest-common-supersequence/
//
/*
* Expected Time Complexity: O(Length(X) * Length(Y)).
Expected Auxiliary Space: O(Length(X) * Length(Y)).

Constraints:
1<= |X|, |Y| <= 100
*/


#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

namespace ShortestCommonSupersequence
{
    // X : 1st given string of size m
    // Y : 2nd given string of size n

    void shortestCommonSupersequenceSub(char* super, int pos, char* second, int& shortest)
    {
        int len = strlen(super);

        if (strlen(second) == 0)
        {
            //cout << super << ", len=" << len << endl;

            if (len < shortest)
            {
                shortest = len;
            }

            return;
        }

        if (len >= shortest)
        {
            //cout << "Current Common Supersequence (" << super << ") has length of " << len << ", great or equal to shortest. drop." << endl;

            return;
        }

        int i;
        for (i = pos; i <= len; i++)
        {
            char arr[10001];
            if (i == 0)
            {
                arr[0] = second[0];
                strncpy(&arr[1], super, len);
                arr[len + 1] = 0x0;
            }
            else if (i == len)
            {
                strcpy(arr, super);
                arr[len] = second[0];
                arr[len + 1] = 0x0;
            }
            else
            {
                if (super[i] != second[0])
                {
                    strncpy(arr, super, i);
                    arr[i] = second[0];
                    strncpy(&arr[i + 1], &super[i], len - i);
                    arr[len+1] = 0x0;
                }
                else
                {
                    strcpy(arr, super);
                }
            }
            shortestCommonSupersequenceSub(arr, i+1, &second[1], shortest);
        }

    }
    int shortestCommonSupersequence(char* X, char* Y, int m, int n) 
    {
        //code here
        int len = INT_MAX;

        shortestCommonSupersequenceSub(X, 0, Y, len);

        return len;
    }
};

namespace SCS
{
    int shortestCommonSupersequence(char* X, char* Y, int m, int n)
    {
        //code here
        cout << "m = " << m << ", n = " << n << endl;

        if (m == 0)  return n;
        if (n == 0)  return m;

        if (X[m - 1] == Y[n - 1])
        {
            return 1 + shortestCommonSupersequence(X, Y, m - 1, n - 1);
        }
        else
        {
            int ret1 = shortestCommonSupersequence(X, Y, m - 1, n);
            int ret2 = shortestCommonSupersequence(X, Y, m, n - 1);

            return (ret1 < ret2) ? ret1 +1 : ret2+1;
        }
    }
};

namespace SCS_DP
{
    int shortestCommonSupersequence(char* X, char* Y, int m, int n)
    {
        int** dp;
        dp = new int* [m + 1];
        for (int i = 0; i < m + 1; i++)
        {
            dp[i] = new int[n + 1];
        }

        for (int i = 0; i < m + 1; i++)
        {
            for (int j = 0; j < n + 1; j++)
            {
                dp[i][j] = 0;
            }
        }

        char arr[1001];
        
        for (int i = 0; i <= m; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0)    dp[i][j] = j;

                else if (j == 0) dp[i][j] = i;

                else if (X[i-1] == Y[j-1])
                {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }

                else
                {
                    int ret1 = dp[i - 1][j];
                    int ret2 = dp[i][j - 1];

                    dp[i][j] = (ret1 < ret2) ? 1 + dp[i - 1][j] : 1 + dp[i][j - 1];
                }
            }

        }
        /*
        // Fill table in bottom up manner
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                // Below steps follow above recurrence
                if (!i)
                    dp[i][j] = j;
                else if (!j)
                    dp[i][j] = i;
                else if (X[i - 1] == Y[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                else
                    dp[i][j]
                    = 1 + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        */
        int index = dp[m][n];
        string str;

        int i = m;
        int j = n;
        while (i > 0 && j > 0)
        {
            if (X[i - 1] == Y[j - 1])
            {
                str.push_back(X[i - 1]);
                i--;
                j--;
                index--;
            }
            else if (dp[i - 1][j - 1] > dp[i][j - 1])
            {
                str.push_back(Y[j - 1]);
                j--;
                index--;
            }
            else
            {
                str.push_back(X[i - 1]);
                i--;
                index--;
            }
        }

        while (i > 0)
        {
            str.push_back(X[i - 1]);
            i--;
            index--;
        }

        while (j > 0)
        {
            str.push_back(Y[j - 1]);
            j--;
            index;
        }

        reverse(str.begin(), str.end());

        cout << str << endl;
        return dp[m][n];



    }
};


int ShortestCommonSupersequence_Test()
{
    int t;
    char X[10001], Y[10001];

    /*
    //taking total testcases
    cin >> t;
    while (t--) {

        //taking String X and Y
        cin >> X >> Y;

        //calling function shortestCommonSupersequence()
        cout << ShortestCommonSupersequence::shortestCommonSupersequence(X, Y, strlen(X), strlen(Y)) << endl;
    }
    */

    strcpy(X, "efgh");
    strcpy(Y, "jghi");

    //cout << ShortestCommonSupersequence::shortestCommonSupersequence(X, Y, strlen(X), strlen(Y)) << endl;
   cout << SCS_DP::shortestCommonSupersequence(X, Y, strlen(X), strlen(Y)) << endl;

    return 0;

}
