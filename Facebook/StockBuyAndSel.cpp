/*
* https://practice.geeksforgeeks.org/problems/stock-buy-and-sell-1587115621/1
*/

/*
* 
The cost of stock on each day is given in an array A[] of size N. Find all the days on which you buy and sell the stock 
so that in between those days your profit is maximum.
Note: There may be multiple possible solutions. Return any one of them.
* 
*/

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>
#include <stdlib.h>
#include <string>
#include <sstream>      // std::istringstream
#include <queue>


using namespace std;

namespace StockBuyAndSel
{
    int check(vector<vector<int>> ans, vector<int> A, int p)
    {
        int c = 0;
        for (int i = 0; i < ans.size(); i++)
            c += A[ans[i][1]] - A[ans[i][0]];
        return (c == p) ? 1 : 0;
    }


    class Solution 
    {
    public:
        //Function to find the days of buying and selling stock for max profit.
        vector<vector<int> > stockBuySell(vector<int> A, int n) 
        {
            // code here
            vector<vector<int>> ret;
            vector<int> entry;

            int max = INT_MIN;
            int startPos = 0;
            int i = 0;

            for (i = 0; i < n; i++)
            {
                if (A[i] < max)
                {
                    if (startPos < (i - 1))
                    {
                        entry.push_back(startPos);
                        entry.push_back(i - 1);

                        ret.push_back(entry);
                        startPos = i;
                    }
                }
                max = A[i];
            }
            entry.push_back(startPos);
            entry.push_back(i - 1);

            ret.push_back(entry);


            return ret;
        }
    };
};

int StockBuyAndSel_Test()
{
    /*
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; ++i) {
            cin >> A[i];
        }
        StockBuyAndSel::Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for (int i = 0; i < n - 1; i++)
        {
            int x = A[i + 1] - A[i];
            if (x > 0)
                p += x;
        }
        if (ans.size() == 0)
            cout << "No Profit";
        else {
            cout << StockBuyAndSel::check(ans, A, p);
        }cout << endl;
    }
    */

    vector<int> A { 100, 180, 260, 310, 40, 535, 695 };
    int n = A.size();

    StockBuyAndSel::Solution ob;
    vector<vector<int> > ans = ob.stockBuySell(A, n);
    int p = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int x = A[i + 1] - A[i];
        if (x > 0)
            p += x;
    }
    if (ans.size() == 0)
        cout << "No Profit";
    else {
        cout << StockBuyAndSel::check(ans, A, p);
    }cout << endl;

    return 0;
}
