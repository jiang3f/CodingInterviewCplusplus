/*
*
2. Remove the fewest charaters to balance the open/close parenthesis.
e.g.:

balance("a(b)") ="a(b)"
balance(")(") = "";
balance("(a(b)c(d(d)") = "a(b)cd(d)"
*/

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>
#include <stack>

using namespace std;

// My solution is wrong

namespace BalancedParentheses
{
    string Balance(string s)
    {
        stack<int> st;
        string ret;

        for (int i = 0; i < s.length(); i++)
        {
            char p = s.at(i);
            if (p == '(')
            {
                st.push(i);
            }
            else if (p == ')')
            {
                if (st.empty() == true) return "";

                st.pop();
            }
        }

        if (st.empty() == true) return s;

        int begin = 0;
        int end = s.length();
        while (st.empty() == false)
        {
            begin = st.top();
            st.pop();

            ret = s.substr(begin+1, end - begin - 1) + ret;
            end = begin;
        }
        
        return ret;
    }
};

int BalancedParentheses_Test()
{
    string s = "(a(b)c(d(d)";

    cout << BalancedParentheses::Balance(s) << endl;

    return 0;
}


