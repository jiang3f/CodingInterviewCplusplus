//
//https://www.geeksforgeeks.org/print-all-combinations-of-balanced-parentheses/
// 

#include "stdafx.h"
#include <iostream>
#include <stack>
#include <list>

using namespace std;
namespace PrintAllCombinationsOfBalancedParentheses
{
    void printParenthesis(string s, int openCount, int closeCount, int n)
    {
        if (openCount == n && closeCount == n)
        {
            cout << s << endl;
            return;
        }

        if (openCount > closeCount)
        {
            string s1 = s + "}";
            printParenthesis(s1, openCount, closeCount + 1, n);
        }
        
        if (openCount < n)
        {
            string s1 = s + "{";
            printParenthesis(s1, openCount + 1, closeCount, n);
        }

    }

    void printParenthesis_FavoriteOpen(string s, int openCount, int closeCount, int n)
    {
        if (openCount == n && closeCount == n)
        {
            cout << s << endl;
            return;
        }

        if (openCount < n)
        {
            string s1 = s + "{";
            printParenthesis_FavoriteOpen(s1, openCount + 1, closeCount, n);
        }

        if (openCount > closeCount)
        {
            string s1 = s + "}";
            printParenthesis_FavoriteOpen(s1, openCount, closeCount + 1, n);
        }

    }



    void Run(int n)
    {
        string s;

        printParenthesis_FavoriteOpen(s, 0, 0, n);

        //printParenthesis(s, 0, 0, n);
    }
};

// Driven Program 
int PrintAllCombinationsOfBalancedParentheses_Test()
{
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        PrintAllCombinationsOfBalancedParentheses::Run( n);
        cout << endl;

    }
    return 0;
}