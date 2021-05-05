/*
* https://www.geeksforgeeks.org/facebook-interview-set-1/?ref=rp
* https://practice.geeksforgeeks.org/problems/palindrome-string0817/1
*/


#include "stdafx.h"
#include <iostream>
#include <queue>
#include <string>

using namespace std;

// My solution is wrong

namespace CheckIfStringIsPalindrome
{
    class Solution 
    {
    public:


        int isPlaindrome(string S)
        {
            // Your code goes here
            if (S.length() == 0)    return 1;

            char* pLeft = (char *)S.c_str();
            char* pRight = (char *)(S.c_str() + S.length() - 1);

            while (pLeft < pRight)
            {
                if (*pLeft != *pRight)  return 0;
                pLeft++;
                pRight--;
            }
            return 1;

        }

    };
};

int CheckIfStringIsPalindrome_Test()
{
    /*
    int t;
    scanf("%d", &t);
    while (t--)
    {
        char s[100000];
        scanf("%s", &s);;

        printf("%d\n", isPlaindrome(s));
    }
    */

    string s = "abba";

    CheckIfStringIsPalindrome::Solution so;

    printf("%d\n", so.isPlaindrome(s));

    return 0;


}
