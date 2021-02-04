//
// https://practice.geeksforgeeks.org/problems/palindromic-patitioning4845/1
// https://www.geeksforgeeks.org/palindrome-partitioning-dp-17/
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <map>
#include <string>

using namespace std;
namespace PalindromicPatitioning
{
    class Solution {

    private:

        string FindLast(string s)
        {
            std::size_t found = s.find_last_of(',');
            if (found != 0)
                return s.substr(found + 1);
            else
                return s;
        }

        bool IsPalindrome(const char* str)
        {
            int len = (int)strlen(str);
            for (int i = 0; i < len / 2; i++)
            {
                if (str[i] != str[len - 1 - i]) return false;
            }
            return true;
        }

    public:
        int PalindromeSub(queue<string> strQ, const char* s)
        {
            queue<string> newQueue;

            if (strlen(s) == 0)
            {
                int ret = INT_MAX;

                while (strQ.size() != 0)
                {
                    string s1 = strQ.front();
                    strQ.pop();

                    if (s1.back() == ',')
                    {
                        int cnt = (int)std::count(s1.begin(), s1.end(), ',');
                        if (cnt != 0 && cnt < ret)  ret = cnt;
                    }
                }
                return ret-1;
            }

            else if (strQ.size() == 0)
            {
                string newStr = string(1, *s);
                newQueue.push(newStr);
                newStr.push_back(',');
                newQueue.push(newStr);
            }
            else
            {

                while (strQ.size() != 0)
                {
                    string cur = strQ.front();
                    strQ.pop();

                    string p = cur + *s;
                    newQueue.push(p);

                    string sub = FindLast(p);
                    if (sub.empty() != true)
                    {
                        if (IsPalindrome(sub.c_str()))
                        {
                            p = p + ',';
                            newQueue.push(p);
                        }
                    }
                }
            }

            return PalindromeSub(newQueue, s + 1);
        }

        int palindromicPartition(string str)
        {
            // code here

            queue<string> q;
            int ret = PalindromeSub(q, str.c_str());

            return ret;
        }
    };
};

namespace PalindromicPatitioning_Dp
{
    class Solution
    {
    public:
        // Returns the minimum number of cuts 
        // needed to partition a string 
        // such that every part is a palindrome 
        int minPalPartion(string str)
        {
            // Get the length of the string 
            int n = str.length();

            /* Create two arrays to build the solution
            in bottom up manner
            C[i][j] = Minimum number of cuts needed for
                    palindrome partitioning
                    of substring str[i..j]
            P[i][j] = true if substring str[i..j] is
                    palindrome, else false
            Note that C[i][j] is 0 if P[i][j] is true */
            int** C = new int* [n];
            for (int i = 0; i < n; i++)
            {
                C[i] = new int[n];
            }

            bool** P = new bool* [n];
            for (int i = 0; i < n; i++)
            {
                P[i] = new bool[n];
            }

            // Every substring of length 1 is a palindrome 
            for (int i = 0; i < n; i++) {
                P[i][i] = true;
                C[i][i] = 0;
            }

            /* L is substring length. Build the
            solution in bottom up manner by
            considering all substrings of
            length starting from 2 to n.
            The loop structure is same as Matrx
            Chain Multiplication problem
            ( See https:// www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/ )*/
            for (int L = 2; L <= n; L++) {

                // For substring of length L, set 
                // different possible starting indexes 
                for (int i = 0; i < n - L + 1; i++) {
                    int j = i + L - 1; // Set ending index 

                    // If L is 2, then we just need to 
                    // compare two characters. Else 
                    // need to check two corner characters 
                    // and value of P[i+1][j-1] 
                    if (L == 2)
                        P[i][j] = (str[i] == str[j]);
                    else
                        P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];

                    // IF str[i..j] is palindrome, then C[i][j] is 0 
                    if (P[i][j] == true)
                        C[i][j] = 0;
                    else {

                        // Make a cut at every possible 
                        // location starting from i to j, 
                        // and get the minimum cost cut. 
                        C[i][j] = INT_MAX;
                        for (int k = i; k <= j - 1; k++)
                            C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1);
                    }
                }
            }

            // Return the min cut value for 
            // complete string. i.e., str[0..n-1] 
            return C[0][n - 1];
        }
    };
};

namespace PalindromicPatitioning_Dp1
{
    // A utility function to get minimum of two integers 
    int min(int a, int b) { return (a < b) ? a : b; }

    // Returns the minimum number of cuts needed to partition a string 
    // such that every part is a palindrome 
    int minPalPartion(char* str)
    {
        // Get the length of the string 
        int n = strlen(str);

        /* Create two arrays to build the solution in bottom-up manner
        C[i] = Minimum number of cuts needed for a palindrome partitioning
                    of substring str[0..i]
        P[i][j] = true if substring str[i..j] is palindrome, else false
        Note that C[i] is 0 if P[0][i] is true */
        int *C = new int [n];

        bool **P;
        P = new bool* [n];
        for (int i = 0; i < n; i++)
        {
            P[i] = new bool[n];
        };

        int i, j, k, L; // different looping variables 

        // Every substring of length 1 is a palindrome 
        for (i = 0; i < n; i++) {
            P[i][i] = true;
        }

        /* L is substring length. Build the solution in bottom up manner by
        considering all substrings of length starting from 2 to n. */
        for (L = 2; L <= n; L++) {
            // For substring of length L, set different possible starting indexes 
            for (i = 0; i < n - L + 1; i++) {
                j = i + L - 1; // Set ending index 

                // If L is 2, then we just need to compare two characters. Else 
                // need to check two corner characters and value of P[i+1][j-1] 
                if (L == 2)
                    P[i][j] = (str[i] == str[j]);
                else
                    P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
            }
        }

        for (i = 0; i < n; i++) {
            if (P[0][i] == true)
                C[i] = 0;
            else {
                C[i] = INT_MAX;
                for (j = 0; j < i; j++) {
                    if (P[j + 1][i] == true && 1 + C[j] < C[i])
                        C[i] = 1 + C[j];
                }
            }
        }

        // Return the min cut value for complete string. i.e., str[0..n-1] 
        return C[n - 1];
    }
};

namespace PalindromicPatitioning_Dp_Tabulation
{
    bool ispallindrome(string input, int start, int end)
    {
        // Using two pointer technique to check pallindrome 
        while (start < end) {
            if (input[start] != input[end])
                return false;
            start++;
            end--;
        }
        return true;
    }

    int MinPalpartiion(string s, int n)
    {
        int m[100][100];

        for (int i = 0; i < 100; i++)
        {
            for (int j = 0; j < 100; j++)
            {
                m[i][j] = -1;
            }
        }

        for (int i = 0; i < 100; i++)    m[i][i] = 0;

        int pal = INT_MAX;

        for (int ln = 1; ln <= n; ln++)
        {
            for (int i = 0; i < n - ln + 1; i++)
            {
                int j = i + ln - 1;
                m[i][j] = INT_MAX;

                if (ispallindrome(s, i, j) == true)
                {
                    m[i][j] = 0;
                }
                else
                {
                    for (int k = i; k <= j - 1; k++)
                    {
                        pal = m[i][k] + m[k + 1][j] + 1;
                        if (pal < m[i][j])
                            m[i][j] = pal;
                    }
                }
                cout << "m[" << i << "][" << j << "]=" << m[i][j] << endl;
            }
        }

        return m[0][n-1];

    }

    int Run(string s)
    {
        int n = s.length();

        if (n == 0 || n == 1)   return 0;

        int ret = MinPalpartiion (s, n);

        return ret;
    }
};

// Driven Program 
int PalindromicPatitioning_Test ()
{
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;

        //PalindromicPatitioning::Solution ob;
        //cout << ob.palindromicPartition(str) << "\n";

        //PalindromicPatitioning_Dp::Solution ob;
        //cout << ob.minPalPartion(str) << "\n";

        //cout << PalindromicPatitioning_Dp1::minPalPartion((char *)str.c_str()) << "\n";

        cout << PalindromicPatitioning_Dp_Tabulation::Run(str) << "\n";

    }
    return 0;
}