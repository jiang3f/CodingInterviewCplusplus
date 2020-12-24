//
// https://www.geeksforgeeks.org/tiling-problem/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace TilingProblem
{
    class Solution {
    public:
        unsigned long long numberOfWays(unsigned long long N) 
        {
            //code here
            if (N == 0 || N == 1)   return 1;

            unsigned long long* arr = new unsigned long long[N + 1];

            arr[0] = arr[1] = 1;

            for (unsigned long long i = 2; i <= N; i++)
            {
                arr[i] = arr[i - 2] + arr[i - 1];

                if (arr[i] < 0)
                {
                    int test = arr[i];

                }
            }

            unsigned long long ret = arr[N] % 1000000007;
        }
    };

};

// Driven Program 
int TilingProblem_Test()
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        TilingProblem::Solution so;
        cout << so.numberOfWays (n)<< endl;
    };

    return 0;

}