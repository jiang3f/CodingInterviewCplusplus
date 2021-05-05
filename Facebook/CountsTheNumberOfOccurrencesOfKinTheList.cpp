/*
* https://www.geeksforgeeks.org/facebook-nyc-onsite-interview-experience/
*/

/*
*
 Write a function that takes a sorted list of integers and a target value k 
 and counts the number of occurrences of k in the list.
 */

#include "stdafx.h"
#include <iostream>
#include <list>


using namespace std;

namespace CountsTheNumberOfOccurrencesOfKinTheList
{
    int Run(list<int> l, int k)
    {
        list<int>::iterator it;
        int count = 0;
        for (it = l.begin(); it != l.end(); it++)
        {
            if (*it > k)    break;
            
            if (*it == k)   count++;
        }
        return count;

    }
};

int CountsTheNumberOfOccurrencesOfKinTheList_Test()
{
    list<int> l;
    int arr[] = { 2, 1, 3, 10, 22, 334, 5, 7, 5, 89, 3, 7, 8 };
    int k = 7;
    for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        l.push_back(arr[i]);
    }

    l.sort();

    cout << "count: " << CountsTheNumberOfOccurrencesOfKinTheList::Run(l, k) << endl;

    return 0;
}
