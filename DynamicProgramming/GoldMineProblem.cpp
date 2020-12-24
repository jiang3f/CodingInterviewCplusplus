//
// https://www.geeksforgeeks.org/gold-mine-problem/?ref=lbp
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace GoldMineProblem
{
    int RunSub(int x, int y, int** arr, int n, int m)
    {
        int ret = INT_MIN;

        if (x == n - 1)   return arr[x][y];
        else
        {
            int ret1, ret2, ret3;
            ret1 = ret2 = ret3 = INT_MIN;

            if (y > 0)
            {
                ret1 = arr[x][y] + RunSub(x + 1, y - 1, arr, n, m);
            }
            
            ret2 = arr[x][y] + RunSub(x + 1, y, arr, n, m);

            if (y < (m - 1))
            {
                ret3 = arr[x][y] + RunSub(x + 1, y + 1, arr, n, m);
            }

            ret = std::max(std::max(ret1, ret2), ret3);

            return ret;
        }
    }

    int Run(int n, int m, int** arr)
    {
        if (n <= 0 || m <= 0)   return 0;

        int ret = INT_MIN;
        for (int i = 0; i < m; i++)
        {
            int ret1 = RunSub(0, i, arr, n, m);
            if (ret1 > ret) ret = ret1;
        }

        return ret;
    }
};

// Driven Program 
int GoldMineProblem_Test()
{
    int T;
    //taking testcases
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        
        int** arr = new int* [n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = new int[m];
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> arr[j][i];
            }
        }

        cout << GoldMineProblem::Run (n, m, arr) << endl;
    };

    return 0;

}