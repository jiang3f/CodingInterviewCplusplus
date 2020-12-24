//
// https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
// https://practice.geeksforgeeks.org/problems/ncr/0
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace BinomialCoefficient
{
    class Solution {
    
    public:
        #define MAX_N   1000
        #define MAX_R   800

        Solution()
        {
            for (int i = 0; i < MAX_N+1; i++)
            {
                arr[i] = new long long[MAX_R+1];

                for (int j = 0; j < MAX_R + 1; j++)
                {
                    arr[i][j] = 0;
                }
            }
        };
        ~Solution()
        {
            for (int i = 0; i < MAX_N+1; i++)
            {
                delete arr[i];
            }
        }


        long long nCr_Sub (int n, int r) {
            // code here
            if (r > n)  return 0;
            else if (r == 0) 
                return 1;
            else if (n == r)    
                return 1;
            else if (arr[n][r] != 0)    return arr[n][r];
            else
            {
                long long leftTop = nCr(n - 1, r - 1);
                long long rightTop = nCr(n - 1, r);
                long long ret = leftTop + rightTop;
                arr[n][r] = ret;
                return ret ;
            }
        }

        int nCr (int n, int r)
        {
            long long ret = nCr_Sub(n, r);

            return int (ret % 1000000007);
        }

    private:
        long long *arr[MAX_N+1];

    };

};

// Driven Program 
int BinomialCoefficient_Test()
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        int n, r;
        cin >> n >> r;
        BinomialCoefficient::Solution ob;
        cout << ob.nCr(n, r) << endl;
    };

    return 0;

}