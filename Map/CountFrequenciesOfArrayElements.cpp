/*
* https://pencilprogrammer.com/cpp-programs/count-frequencies-of-array-elements/


Input:  {1, 1, 2, 1, 2}

Output: 1 : 3
        2 : 2
*/

#include "stdafx.h"
#include <iostream>
#include <map>

using namespace std;

namespace CountFrequenciesOfArrayElements
{
    class Solution_TwoLoop
    {
    public:

        void CountFrequencies(int arr[], int n)
        {
            bool* isvisit = new bool[n];
            for (int i = 0; i < n; i++)   isvisit[i] = false;

            for (int i = 0; i < n; i++)
            {
                if (isvisit[i] == false)
                {
                    int freq = 1;

                    for (int j = i + 1; j < n; j++)
                    {
                        if (arr[i] == arr[j])
                        {
                            freq++;
                            isvisit[j] = true;
                        }
                    }

                    cout << arr[i] << ": " << freq << endl;
                }
            }
        }
    };

    class Solution_Map
    {
    public:

        void CountFrequencies(int arr[], int n)
        {
            map<int, int> myMap;

            for (int i = 0; i < n; i++)
            {
                myMap[arr[i]] ++;
            }

            for (map<int, int>::iterator it = myMap.begin(); it != myMap.end(); it++)
            {
                cout << it->first << ": " << it->second << endl;
            }
              
        }
    };

};

int CountFrequenciesOfArrayElements_Test()
{
    int array[] = { 1, 1, 2, 1, 2 };
    int n = sizeof(array) / sizeof(int);

    CountFrequenciesOfArrayElements::Solution_TwoLoop ob;

    ob.CountFrequencies(array, n);

    CountFrequenciesOfArrayElements::Solution_Map ob1;

    ob1.CountFrequencies(array, n);

    return 0;

}
