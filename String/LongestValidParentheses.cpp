/*
* https://leetcode.com/problems/longest-valid-parentheses/
*/

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

namespace LongestValidParentheses
{
    class Solution {
    public:
        bool IsValid(string s)
        {
            int total = 0;
            const char* p = s.c_str();
            while (*p != '\0')
            {
                if (total < 0)  break;
                else if (*p == '(') total++;
                else total--;
                p++;
            }
            if (total == 0) return true;
            else    return false;
        }

        int longestValidParentheses(string s) {
            int size = s.length();
            int max = 0;
            for (int i = 0; i < size - 1; i++)
            {
                if (s.at(i) == ')') continue;

                for (int j = i + 1; j < size; j++)
                {
                    if (s.at(j) == '(')    continue;
                    int len = j - i + 1;
                    string substr = s.substr(i, len);
                    if (IsValid(substr))
                    {
                        if (len > max)  max = len;

                    }
                }
            }

            return max;
        }
    };

    class Solution_use_stack
    {
    public:
        int longestValidParentheses(string s)
        {
            stack<int> stk;
            stk.push (-1);

            const char* p = s.c_str();
            int i = 0;
            int max = 0;
            while (*p != '\0')
            {
                if (*p == '(')
                {
                    stk.push(i);
                }
                else
                {
                    stk.pop();

                    if (stk.empty())
                    {
                        stk.push(i);
                    }
                    else
                    {
                        int len = i - stk.top();
                        if (max < len)
                        {
                            max = len;
                        }
                    }

                }
                i++;
                p++;
            }

            return max;

        }
    };
};

int LongestValidParentheses_Test()
{
    string s = "(())()(()((";

    LongestValidParentheses::Solution_use_stack ob;

    cout << ob.longestValidParentheses(s) << endl;

    return 0;
}

