/*
* 
* Facebook screening interview question
* 
* https://leetcode.com/discuss/interview-question/algorithms/124820/continuous-sequence-against-target-number
* 
*/

#include "stdafx.h"
#include <iostream>
#include <map>
#include <strstream>
#include <strstream>

using namespace std;

namespace FindAllSequenceThatSumEqualToTarget
{
    map<string, map<string, int>> rangeCombination;
    map<string, int> elementCombination;

    string makeKey(int a1, int a2)
    {
        strstream ss;
        if (a1 != a2)        ss << a1 << "," << a2 << ends;
        else ss << a1 << ends;
        return ss.str();
    }

    string connectKeys(string k1, string k2)
    {
        return k1 + "," + k2;
    }

    map<string, int> mergeKeys(map<string,int> left, map<string, int> right, int sum)
    {
        map<string, int> ret;

        for (map<string, int>::iterator it1 = left.begin(); it1 != left.end(); it1++)
        {
            ret.insert(*it1);

            for (map<string, int>::iterator it2 = right.begin(); it2 != right.end(); it2++)
            {
                ret.insert(*it2);

                string key = connectKeys(it1->first, it2->first);

                if (elementCombination.find(key) == elementCombination.end())
                {
                    elementCombination[key] = it1->second + it2->second;

                    if ((it1->second + it2->second) == sum)
                    {
                        cout << "key = " << key << endl;
                    }
                }

            }
        }

        return ret;
    }

    map<string, int> sub(int arr[], int a1, int a2, int sum)
    {
        string key = makeKey(a1, a2);

        // memorize
        if (rangeCombination.find(key) != rangeCombination.end())
        {
            return rangeCombination[key];
        }

        // new combination
        map<string, int> values;

        if (a1 == a2)
        {
            if (elementCombination.find (key) == elementCombination.end())
            {
                elementCombination[key] = arr[a1];
            }

            //
            if (arr[a1] == sum)
            {
                cout << "key = " << a1 << endl;
            }
            values[key] = arr[a1];
            rangeCombination[key] = values;
            
            return values;
        }

        for (int l = 0; l < a2 - a1; l++)
        {
            //left
            map<string, int> left = sub(arr, a1, a1 + l, sum);

            // right
            map<string, int> right = sub(arr, a1 + l + 1, a2, sum);

            map<string, int> total = mergeKeys(left, right, sum);

            for (map<string, int>::iterator it = total.begin(); it != total.end(); it++)
            {
                values.insert(*it);
            }
        }
        rangeCombination[key] = values;

        return values;
    }

    void Run(int arr[], int n, int sum)
    {
        map<string, int> ret = sub (arr, 0, n - 1, sum);
        
    }
};


int FindAllSequenceThatSumEqualToTarget_Test()
{
    int arr[] = { 1,2,3,5 };
    int k = 7;

    FindAllSequenceThatSumEqualToTarget::Run(arr, sizeof(arr) / sizeof(arr[0]), k);

    return 0;
}