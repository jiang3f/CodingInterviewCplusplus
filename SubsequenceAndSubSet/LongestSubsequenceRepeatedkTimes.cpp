//
// https://leetcode.com/contest/weekly-contest-259/problems/longest-subsequence-repeated-k-times/


/*
You are given a string s of length n, and an integer k.You are tasked to find the longest subsequence repeated k times in string s.

A subsequence is a string that can be derived from another string by deleting some or no characters without changing the order of the remaining characters.

A subsequence seq is repeated k times in the string s if seq* k is a subsequence of s, where seq* k represents a string constructed by concatenating seq k times.

For example, "bba" is repeated 2 times in the string "bababcba", because the string "bbabba", constructed by concatenating "bba" 2 times, is a subsequence of the string "bababcba".

Return the longest subsequence repeated k times in string s.If multiple such subsequences are found, return the lexicographically largest one.If there is no such subsequence, return an empty string.



Example 1:
example 1

Input : s = "letsleetcode", k = 2
Output : "let"
Explanation : There are two longest subsequences repeated 2 times : "let" and "ete".
"let" is the lexicographically largest one.

Example 2 :

    Input : s = "bb", k = 2
    Output : "b"
    Explanation : The longest subsequence repeated 2 times is "b".

    Example 3 :

    Input : s = "ab", k = 2
    Output : ""
    Explanation : There is no subsequence repeated 2 times.Empty string is returned.

    Example 4 :

    Input : s = "bbabbabbbbabaababab", k = 3
    Output : "bbbb"
    Explanation : The longest subsequence "bbbb" is repeated 3 times in "bbabbabbbbabaababab".



Constraints:

n == s.length
2 <= n, k <= 2000
2 <= n < k * 8
s consists of lowercase English letters.
*/

// 

#include "stdafx.h"
#include <iostream>
#include <string>
#include <map>
#include <queue>

using namespace std;

namespace LongestSubsequenceRepeatedkTimes
{
    class Solution
    {
    private:

        void RecPermutation(string sofar, string remaining)
        {
            if (remaining.empty())
            {
                cout << sofar << endl;
            }
            else
            {
                for (int i = 0; i < remaining.length(); i++)
                {
                    string remaining1 = remaining.substr(0, i) + remaining.substr(i + 1);
                    RecPermutation(sofar + remaining[i], remaining1);
                }
            }
        }

        void RecSubsequence (string sofar, string remaining, map<string, int>& m)
        {
            if (!sofar.empty())
            {
                cout << sofar << endl;
                m[sofar] += 1;
            }

            for (int i = 0; i < remaining.length(); i++)
            {
                string remaining1 = remaining.substr(i + 1);
                RecSubsequence(sofar + remaining[i], remaining1, m);
            }

        }

        void RecSubset(string sofar, string remaining, map<string, int>& m)
        {
            if (remaining.empty())
            {
                cout << sofar << endl;
                m[sofar] += 1;
            }
            else
            {
                RecSubset(sofar + remaining[0], remaining.substr(1), m);
                RecSubset(sofar, remaining.substr(1), m);
            }
        }
    public:
        int Run (string s, int k)
        {
            map<string, int> m;
            
            //RecSubset("", s, m);
            RecSubsequence("", s, m);

            int maxLen = 0;

            for (map<string, int>::iterator it = m.begin(); it != m.end(); it++)
            {
                if (it->second == k)
                {
                    int len = it->first.length();
                    maxLen = max(maxLen, len);
                }
            }

            return maxLen;
        }
    };

    // https://leetcode.com/problems/longest-subsequence-repeated-k-times/discuss/1471911/Java-BFS-O(n-*-2-8)-with-detailed-explanation
    class Solution_Bfs
    {
    private:
        bool isSub(string s, string sub, int k)
        {
            int j = 0;
            int repeat = 0;

            for (int i = 0; i < s.length(); i++)
            {
                if (s.at(i) == sub.at(j))
                {
                    j++;

                    if (j == sub.length())
                    {
                        repeat++;

                        if (repeat == k)    return true;

                        j = 0;
                    }
                }
            }
            return false;
        }

    public:
        string Run(string s, int k)
        {
            string ret;

            int charCnt[26];

            memset(charCnt, 0, sizeof(int) * 26);

            for (int i = 0; i < s.length(); i++)
            {
                charCnt[s.at(i) - 'a'] ++;
            }

            queue<string> q;
            q.push("");

            while (!q.empty())
            {
                string cur = q.front();
                q.pop();

                for (int i = 0; i < 26; i++)
                {
                    if (charCnt[i] >= k)
                    {
                        string next = cur + (char)('a' + i);

                        if (isSub(s, next, k))
                        {
                            ret = next;

                            q.push(cur + (char)('a' + i));
                        }
                    }
                }
            }

            return ret;
        }
    };
};

int LongestSubsequenceRepeatedkTimes_Test()
{
    string s = "letsleetcode";
    //string s = "abcd";

    // expected result: {"abcd", "abc", "abd", "ab", "acd", "ad", "ad, "a", "bcd", "bc", "bd", "b", "cd", "c"};

    int k = 2;

    //LongestSubsequenceRepeatedkTimes::Solution ob;

    LongestSubsequenceRepeatedkTimes::Solution_Bfs ob;

    cout << ob.Run(s, k) << endl;

    return 0;
}
