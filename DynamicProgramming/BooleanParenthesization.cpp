//
// https://www.geeksforgeeks.org/boolean-parenthesization-problem-dp-37/
// https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1
// 

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

namespace BooleanParenthesization
{
    class Solution {
    public:
       unsigned long long countWays(unsigned long long N, string s) 
        {
            // code here
            if ((N % 2) == 0)   return 0;

            return countWaysSub(s, N, 0, N - 1, true);
        }
    private:
        map<string, unsigned long long> dp;

    private:
        string MakeKey(unsigned long long a1, unsigned long long a2, bool expect)
        {
            char buf[250];
            if (expect == true)
                sprintf(buf, "%d,%d,true", a1, a2);
            else
                sprintf(buf, "%d,%d,false", a1, a2);
            string s(buf);
            return s;
        }

        bool IsTrue(bool left, bool right, char op)
        {
            if (op == '|')
            {
                return left | right;
            }
            else if (op == '&')
            {
                return left & right;
            }
            else if (op == '^')
            {
                return left ^ right;
            }
        }

        unsigned long long countWaysSub(string s, unsigned long long n, unsigned long long a1, unsigned long long a2, bool expectResult)
        {
            unsigned long long ret = 0;

            string key = MakeKey(a1, a2, expectResult);

            if (dp.find(key)!= dp.end())
            {
                ret = dp[key];
            }
            else if (a1 == a2)
            {
                bool value = (s.at(a1) == 'T') ? true : false;

                if (value == expectResult)  ret = 1;
                else ret = 0;
            }
            else if ((a2-a2) % 2 != 0)           
            {
                ret = 0;
            }
            else
            {

                for (unsigned long long i = a1; i < a2; i += 2)
                {
                    unsigned long long count = 0;

                    unsigned long long numTrueLeft = countWaysSub(s, n, a1, i, true);
                    unsigned long long numFalseLeft = countWaysSub(s, n, a1, i, false);

                    unsigned long long numTrueRight = countWaysSub(s, n, i + 2, a2, true);
                    unsigned long long numFalseRight = countWaysSub(s, n, i + 2, a2, false);

                    char op = s.at(i + 1);
                    if (op == '&')
                    {
                        if (expectResult == true)
                            count = numTrueLeft * numTrueRight;
                        else
                            count = ((numTrueLeft + numFalseLeft) * (numTrueRight + numFalseRight)) - (numTrueLeft * numTrueRight);
                    }
                    else if (op == '|')
                    {
                        if (expectResult == true)
                            count = (numTrueLeft + numFalseLeft) * (numTrueRight + numFalseRight) - (numFalseLeft * numFalseRight);
                        else
                            count = numFalseLeft * numFalseRight;
                    }
                    else if (op == '^')
                    {
                        if (expectResult == true)
                            count = numTrueLeft * numFalseRight + numFalseLeft * numTrueRight;
                        else
                            count = numTrueLeft * numTrueRight + numFalseLeft * numFalseRight;
                    }

                    ret += count;
                }
            }

            string m = (expectResult == true) ? "true" : "false";

            cout << "[" << a1 << "," << a2 << "] (" << m << ") =" << ret << endl;
            dp[key] = ret;

            return ret;
        }
    };

};

namespace BooleanParenthesization_dp
{
    class Solution {
    public:
        unsigned long long countWays(unsigned long long N, string S)
        {
            // code here
            if ((N % 2) == 0)   return 0;

            unsigned long long** T, **F;
            T = new unsigned long long* [N];
            for (unsigned long long i = 0; i < N; i++)
            {
                T[i] = new unsigned long long[N];
            }
            F = new unsigned long long* [N];
            for (unsigned long long i = 0; i < N; i++)
            {
                F[i] = new unsigned long long[N];
            }

            for (unsigned long long i = 0; i < N; i++)
            {
                for (unsigned long long j = 0; j < N; j++)
                {
                    T[i][j] = 0;
                    F[i][j] = 0;
                }
            }

            for (unsigned long long i = 0; i < N; i++)
            {
                if (S.at(i) == 'T')
                {
                    T[i][i] = 1;
                }
                else
                {
                    F[i][i] = 1;
                }
            }

            for (unsigned long long numOp = 1; numOp <= N / 2; numOp++)
            {
                for (unsigned long long i = 0; i < N - 2; i += 2)
                {
                    unsigned long long j = i + numOp * 2;

                    if (j > N - 1)    continue;

                    for (unsigned long long m = 0; m < numOp; m++)
                    {
                        char op = S.at(i + m * 2 + 1);
                        if (op == '|')
                        {
                            unsigned long long tmp = F[i][i + m * 2] * F[i + m * 2 + 2][j];
                            T[i][j] += ((T[i][i + m * 2] + F[i][i + m * 2]) * (T[i + m * 2 + 2][j] + F[i + m * 2 + 2][j])) - tmp;
                            F[i][j] += tmp;
                        }
                        else if (op == '&')
                        {
                            unsigned long long tmp = T[i][i + m * 2] * T[i + m * 2 + 2][j];
                            F[i][j] += ((T[i][i + m * 2] + F[i][i + m * 2]) * (T[i + m * 2 + 2][j] + F[i + m * 2 + 2][j])) - tmp;
                            T[i][j] += tmp;
                        }
                        else if (op == '^')
                        {
                            unsigned long long tmp = (T[i][i + m * 2] * T[i + m * 2 + 2][j]) + (F[i][i + m * 2] * F[i + m * 2 + 2][j]);
                            T[i][j] += ((T[i][i + m * 2] + F[i][i + m * 2]) * (T[i + m * 2 + 2][j] + F[i + m * 2 + 2][j])) - tmp;
                            F[i][j] += tmp;
                        }
                    }
                    cout << "T[" << i << "][" << j << "]= " << T[i][j] << endl;
                    cout << "F[" << i << "][" << j << "]= " << F[i][j] << endl;
               }
            }
            return T[0][N - 1];

        }
    };
};

namespace BooleanParenthesization_Tabulation
{
    class Solution
    {
    public:
        unsigned long long countWays(unsigned long long N, string S)
        {
            char* symbl = new char[N / 2 + 2];
            char* oper = new char[N / 2 + 1];

            char* p1 = symbl;
            char* p2 = oper;
            char* s = (char *)S.c_str();

            for (unsigned long long i = 0; i < N; i++)
            {
                if ((i % 2) == 0)
                {
                    *(p1++) = *s;
                }
                else
                {
                    *(p2++) = *s;
                }
                s++;
            }
            *p1 = *p2 = 0x0;

            return countParenth(symbl, oper, N / 2 + 1);
        }


        // Returns count of all possible
        // parenthesizations that lead
        // to result true for a boolean 
        // expression with symbols like
        // true and false and operators 
        // like &, | and ^ filled
        // between symbols
        unsigned long long countParenth(char symb[], char oper[], unsigned long long n)
        {
            unsigned long long** F = new unsigned long long* [n];
            for (unsigned long long i = 0; i < n; i++)
            {
                F[i] = new unsigned long long[n];
            }

            unsigned long long** T = new unsigned long long* [n];
            for (unsigned long long i = 0; i < n; i++)
            {
                T[i] = new unsigned long long[n];
            }

            // Fill diaginal entries first
            // All diagonal entries in 
            // T[i][i] are 1 if symbol[i]
            // is T (true). Similarly, 
            // all F[i][i] entries are 1 if
            // symbol[i] is F (False)
            for (unsigned long long i = 0; i < n; i++) {
                F[i][i] = (symb[i] == 'F') ? 1 : 0;
                T[i][i] = (symb[i] == 'T') ? 1 : 0;
            }

            // Now fill T[i][i+1], 
            // T[i][i+2], T[i][i+3]... in order
            // And F[i][i+1], F[i][i+2], 
            // F[i][i+3]... in order
            for (unsigned long long gap = 1; gap < n; ++gap)
            {
                for (unsigned long long i = 0, j = gap;
                    j < n; ++i, ++j)
                {
                    T[i][j] = F[i][j] = 0;
                    for (unsigned long long g = 0;
                        g < gap; g++)
                    {
                        // Find place of parenthesization using
                        // current value of gap
                        unsigned long long k = i + g;

                        // Store Total[i][k] 
                        // and Total[k+1][j]
                        unsigned long long tik = T[i][k] + F[i][k];
                        unsigned long long tkj = T[k + 1][j]
                            + F[k + 1][j];

                        // Follow the recursive formulas 
                        // according
                        // to the current operator
                        if (oper[k] == '&') {
                            T[i][j] += T[i][k]
                                * T[k + 1][j];
                            F[i][j] += (tik * tkj
                                - T[i][k]
                                * T[k + 1][j]);
                        }
                        if (oper[k] == '|') {
                            F[i][j] += F[i][k]
                                * F[k + 1][j];
                            T[i][j] += (tik * tkj
                                - F[i][k]
                                * F[k + 1][j]);
                        }
                        if (oper[k] == '^') {
                            T[i][j] += F[i][k]
                                * T[k + 1][j]
                                + T[i][k]
                                * F[k + 1][j];
                            F[i][j] += T[i][k]
                                * T[k + 1][j]
                                + F[i][k] * F[k + 1][j];
                        }
                    }
                }
            }
            return T[0][n - 1];
        }
    };
}
    
/*
* Input:
197
F|T^T|T|F^F^F|T&T|F^T|F^F^F&T|T^F&T|F&T^T^T&F|T&T^F^F|T&T&F^T^T|T&T^T&T&T^T^F^F^T|F&T^T&F|T&T&F^F&F&F^T^T^F&F&T^T^F^T^F&F|F^F&T|F&F&T&F&F|T^T&T^T&T&F&T|T^T^T|F|F|T|T|F&F&T^T|T^F^T^T^F|F|T^F|T&T^T&F

Its Correct output is:
200

And Your Code's output is:
-90
*/
int BooleanParenthesization_Test()
{
    unsigned long long N = 197;
    string S = "F|T^T|T|F^F^F|T&T|F^T|F^F^F&T|T^F&T|F&T^T^T&F|T&T^F^F|T&T&F^T^T|T&T^T&T&T^T^F^F^T|F&T^T&F|T&T&F^F&F&F^T^T^F&F&T^T^F^T^F&F|F^F&T|F&F&T&F&F|T^T&T^T&T&F&T|T^T^T|F|F|T|T|F&F&T^T|T^F^T^T^F|F|T^F|T&T^T&F";
    
    //unsigned long long N = 3;
    //string S = "T|F";

    BooleanParenthesization_Tabulation::Solution ob;

    unsigned long long ret = ob.countWays(N, S);

    ret = ret % 1003;
    cout << ret << "\n";
    /*
    unsigned long long t;
    cin >> t;
    while (t--) countWays
        unsigned long long N;
        cin >> N;
        string S;
        cin >> S;

        BooleanParenthesization::Solution ob;
        cout << ob.countWays(N, S) << "\n";
    }
    */
    return 0;
}