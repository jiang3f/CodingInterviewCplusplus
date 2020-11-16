//
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
//

#include "stdafx.h"
#include <iostream>
#include <stack>

using namespace std;

namespace LongestIncreasingSubsequence
{
    int Run(int n, int a[])
    {
        stack<int> subSquence;

        if (n == 0) return 0;

        else if (n == 1)    return 1;

        else 
        {
            int minItem = a[0];
            subSquence.push(a[0]);

            for (int i = 1;i < n; i ++)
            {
                int lastItem = subSquence.top();

                if (a[i] > lastItem)
                {
                    subSquence.push(a[i]);
                }
                else
                {
                    subSquence.pop();

                    if (subSquence.size() == 0)
                    {
                        subSquence.push(a[i]);
                    }
                    else
                    {
                        int top = subSquence.top();

                        if ((subSquence.size() == 1) && (minItem < top && minItem < a[i]))
                        {
                            subSquence.pop();
                            subSquence.push(minItem);
                            subSquence.push(a[i]);
                        }
                        else
                        {
                            if (a[i] > top && a[i] < lastItem)
                            {
                                subSquence.push(a[i]);
                            }
                            else
                            {
                                subSquence.push(lastItem);
                            }
                        }
                    }
                }
                if (minItem > a[i])
                {
                    minItem = a[i];
                }
            }
        }

        return subSquence.size();
    }

};


int LongestIncreasingSubsequence_Test()
{
    //taking total testcases
    int t, n;
    cin >> t;
    while (t--)
    {
        //taking size of array
        cin >> n;
        int *a = new int[n];

        //inserting elements to the array
        for (int i = 0; i < n; i++)
            cin >> a[i];

        //calling method longestSubsequence()
        cout << LongestIncreasingSubsequence::Run (n, a) << endl;
    
        delete a;
    }

    return 0;
}

