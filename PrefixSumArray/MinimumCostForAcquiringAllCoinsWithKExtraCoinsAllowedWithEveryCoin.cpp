/*
*https://www.geeksforgeeks.org/minimum-cost-for-acquiring-all-coins-with-k-extra-coins-allowed-with-every-coin/
*/

#include "stdafx.h"
#include <iostream>
#include <time.h>
#include <algorithm>

using namespace std;

namespace MinimumCostForAcquiringAllCoinsWithKExtraCoinsAllowedWithEveryCoin
{
    class Solution
    {
    private:
        void print(int coin[], int n)
        {
            for (int i = 0; i < n; i++)   cout << coin[i] << ",";
            cout << endl;
        }

    public:
        void preprocess(int coin[], int n)
        {
            sort(coin, coin + n);

            print(coin, n);

            for (int i = 1; i < n; i++)
            {
                coin[i] = coin[i - 1] + coin[i];
            }

            print(coin, n);

        }

        int minCost(int coin[], int n, int k)
        {
            int ceil = (n + k) / (k + 1);
            return coin[ceil-1];
        }

    };
};

int MinimumCostForAcquiringAllCoinsWithKExtraCoinsAllowedWithEveryCoin_Test()
{
    int coin[] = { 8, 5, 3, 10, 2, 1, 15, 25 };

    int n = sizeof(coin) / sizeof(coin[0]);
 
    MinimumCostForAcquiringAllCoinsWithKExtraCoinsAllowedWithEveryCoin::Solution ob;

    ob.preprocess(coin, n);
    
    int k = 3;
    cout << ob.minCost(coin, n, k) << endl;
    k = 7;
    cout << ob.minCost(coin, n, k) << endl;

    return 0;
}
