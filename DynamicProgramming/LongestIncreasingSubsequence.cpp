//
// https://practice.geeksforgeeks.org/problems/longest-increasing-subsequence-1587115620/1
//

#include "stdafx.h"
#include <iostream>
#include <list>
#include <vector>

using namespace std;

namespace LongestIncreasingSubsequence
{
    // Time Limit Exceeded
    //
    int Run(int n, int a[])
    {
        list<vector<int>> subSequence;

        if (n == 0) return 0;

        else if (n == 1)    return 1;

        else 
        {
            vector<int> v;
            v.push_back (a[0]);

            subSequence.push_back(v);

            for (int i = 1;i < n; i ++)
            {
                list<vector<int>>::iterator it;
                list<vector<int>> newList;

                for (it = subSequence.begin(); it != subSequence.end(); it++)
                {
                    size_t sz = it->size();
                    if (a[i] > it->at(sz-1))
                    {
                        it->push_back(a[i]);
                    }
                    else if (it->size() == 1 || a[i] > it->at(sz-2))
                    {
                        (*it)[sz-1]= a[i];
                    }
                    else
                    {
                        vector<int> newVec;
                        for (int j = 0; j < it->size(); j++)
                        {
                            if (it->at(j) >= a[i])  break;
                            newVec.push_back(it->at(j));
                        }
                        newVec.push_back(a[i]);

                        newList.push_back(newVec);
                    }
                }

                for (it = newList.begin(); it != newList.end(); it++)
                {
                    subSequence.push_back(*it);
                }
            }

            int maxSeq = 0;
            list<vector<int>>::iterator it;
            for (it = subSequence.begin(); it != subSequence.end(); it++)
            {
                if (it->size() > maxSeq)
                {
                    maxSeq = (int)it->size();
                }
            }

            return maxSeq;
        }

    }

};

namespace LongestIncreasingSubsequence_others
{
    int Run (int n, int arr[])
    {
        // your code here
        if (n == 1 || n == 0)
            return n;

        int *inc = new int[n];
        for (int i = 0; i < n; i++)
            inc[i] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] < arr[i])
                    inc[i] = max(inc[j] + 1, inc[i]);
            }
        }
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            //cout<<inc[i]<<" ";
            maxi = max(maxi, inc[i]);
        }

        delete []inc;

        return maxi;
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
        cout << LongestIncreasingSubsequence_others::Run (n, a) << endl;
    
        delete a;
    }

    return 0;
}

