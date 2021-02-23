//
// https://practice.geeksforgeeks.org/problems/check-frequencies4211/1
/*
*
Expected Time Complexity: O(N) where N is length of str
Expected Auxiliary Space: O(1)


Constraints:
1 <= str.length() <= 4th power of 10
*/
//

#include "stdafx.h"
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

namespace CheckIfFrequenciesCanBeEqual
{
    bool cmp(pair<char, int>& a,
        pair<char, int>& b)
    {
        return a.second > b.second;
    }

    class Solution {
    private:

    public:
        bool sameFreq(string s)
        {
            // code here 
            map<char, int> freq;

            for (int i = 0; i < s.length(); i++)
            {
                freq[s.at(i)] ++;
            }

            if (freq.size() == 2)   return true;

            vector<pair<char, int>> arr;

            map<char, int>::iterator it;
            for (it = freq.begin(); it != freq.end(); it++)
            {
                arr.push_back(*it);
            }

            sort(arr.begin(), arr.end(), cmp);
    
            bool ret = true;

            // remove none
            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i].second != arr[0].second)
                {
                    ret = false;
                    break;
                }
            }
            if (ret == true)    return true;

            // remove front
            ret = true;
            arr[0].second--;
            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i].second != arr[0].second)
                {
                    ret = false;
                    break;
                }
            }
            if (ret == true)    return true;

            ret = true;
            arr[0].second++;
            arr[arr.size() - 1].second--;
            for (int i = 1; i < arr.size(); i++)
            {
                if (arr[i].second != 0)
                {
                    if (arr[i].second != arr[0].second)
                    {
                        ret = false;
                    }
                }
            }
            
            return ret;
        }
    };
};

int CheckIfFrequenciesCanBeEqual_Test()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        CheckIfFrequenciesCanBeEqual::Solution ob;
        cout << ob.sameFreq(s) << endl;
    }
    return 0;

}


