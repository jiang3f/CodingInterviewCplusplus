//
// https://www.geeksforgeeks.org/printing-longest-common-subsequence/
//

///*
//* Expected Time Complexity : O(|str1|*|str2|)
//Expected Auxiliary Space: O(|str1|*|str2|)
///
//Constraints:
//1<=size(str1),size(str2)<=100
//*/

#include "stdafx.h"
#include <iostream>


using namespace std;

namespace LongestCommonSubsequence
{
    void lcs(int x, int y, string s1, string s2, pair<int, string>& max)
    {
        // your code here
        if (x == 0 || y == 0)
        {
            max.first = 0;
            max.second = "";
        }

        else if (s1.at(x - 1) == s2.at(y - 1))
        {
            lcs(x - 1, y - 1, s1.substr(0, s1.length() - 1), s2.substr(0, s2.length() - 1), max);
            max.first++;
            max.second = max.second.append(s1.substr(x - 1, 1));
        }

        else
        {
            pair<int, string> ret1, ret2;

            lcs(x - 1, y, s1.substr(0, s1.length() - 1), s2, ret1);

            lcs(x, y - 1, s1, s2.substr(0, s2.length() - 1), ret2);

            if (ret1.first > ret2.first)
            {
                max.first = ret1.first;
                max.second = ret1.second;
            }
            else
            {
                max.first = ret2.first;
                max.second = ret2.second;
            }
        }
    }

    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        if (x == 0 || y == 0)   return 0;

        if (s1.at(x - 1) == s2.at(y - 1))
        {
            return 1 + lcs(x - 1, y - 1, s1.substr(0, s1.length() - 1), s2.substr(0, s2.length() - 1));
        }

        else
        {
            int ret1 = lcs(x - 1, y, s1.substr(0, s1.length() - 1), s2);
            int ret2 = lcs(x, y - 1, s1, s2.substr(0, s2.length() - 1));

            if (ret1 > ret2)
            {
                return ret1;
            }
            else
            {
                return ret2;
            }
        }
    }
};

namespace LongestCommonSubsequence_DP
{

    int lcsSub(int x, int y, string s1, string s2, int** dp, pair<int, string> &max)
    {
        if (dp[x][y] != -1)
        {
            //cout << "re-visit dp[" << x << "][" << y << "], value=" << dp[x][y] << endl;
            return dp[x][y];
        }

        if (x == 0 || y == 0)
        {
            dp[x][y] = 0;
            max.first = 0;
            max.second = "";
            return dp[x][y];
        }

        else if (s1.at(x - 1) == s2.at(y - 1))
        {
            pair<int, string> next;
            dp[x][y] = 1 + lcsSub(x - 1, y - 1, s1.substr(0, s1.length() - 1), s2.substr(0, s2.length() - 1), dp, next);
            max.first = next.first + 1;
            max.second = next.second + s1.substr(0, 1);
            return dp[x][y];
        }
        else
        {
            pair<int, string> next1, next2;
            int ret1, ret2;
            ret1 = lcsSub(x - 1, y, s1.substr(0, s1.length() - 1), s2, dp, next1);
            ret2 = lcsSub(x, y - 1, s1, s2.substr(0, s2.length() - 1), dp, next2);
            if (ret1 > ret2)
            {
                max.first = next1.first;
                max.second = next1.second;
                dp[x][y] = ret1;
            }
            else
            {
                max.first = next2.first;
                max.second = next2.second;
                dp[x][y] = ret2;
            }
            return dp[x][y];
        }
    }

    int lcs(int x, int y, string s1, string s2)
    {
        int** dp = new int* [x + 1];
        for (int i = 0; i < x + 1; i++)
        {
            dp[i] = new int[y + 1];
        }

        for (int i = 0; i < x + 1; i++)
        {
            for (int j = 0; j < y + 1; j++)
            {
                dp[i][j] = -1;
            }
        }

        pair<int, string> max;
        return lcsSub(x, y, s1, s2, dp, max);
    }
};

int LongestCommonSubsequence_Test()
{
    /*
    int t, n, k, x, y;

    cin >> t;
    while (t--)
    {
        cin >> x >> y;          // Take size of both the strings as input
        string s1, s2;
        cin >> s1 >> s2;        // Take both the string as input

        cout << LongestCommonSubsequence::lcs(x, y, s1, s2) << endl;
    }
    */

    string s1 = "AGGTAB";
    string s2 = "GXTXAYB";
    pair<int, string> max;

    //cout << LongestCommonSubsequence::lcs(6, 6, s1, s2) << endl;

    //LongestCommonSubsequence::lcs(6, 7, s1, s2, max);
    //cout << max.first << ", " << max.second << endl;

    cout << LongestCommonSubsequence_DP::lcs(6, 7, s1, s2) << endl;
    return 0;
}
