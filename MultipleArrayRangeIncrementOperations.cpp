/*
* https://www.geeksforgeeks.org/print-modified-array-multiple-array-range-increment-operations/
* 
*/

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


namespace MultipleArrayRangeIncrementOperations
{
    // structure to store the (start, end) index pair for
    // each query
    struct query {
        int start, end;
    };

    class Solution
    {

    public:

        void incrementByD(int arr[], struct query q_arr[], int n, int m, int d)
        {
            vector<int> sum(n + 1);

            for (int i = 0; i < m; i++)
            {
                sum[q_arr[i].start] += d;
                sum[q_arr[i].end + 1] -= d;
            }

            for (int i = 0; i < n; i++)
            {
                if (i > 0)  sum[i] += sum[i - 1];
                arr[i] += sum[i];
            }

        }

        void printArray(int arr[], int n)
        {
            for (int i = 0; i < n; i++)
                cout << arr[i] << " ";
        }
    };
};

int MultipleArrayRangeIncrementOperations_Test()
{
    int arr[] = { 3, 5, 4, 8, 6, 1 };
    MultipleArrayRangeIncrementOperations::query q_arr[] = { { 0, 3 }, { 4, 5 }, { 1, 4 },
                                       { 0, 1 }, { 2, 5 } };
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = sizeof(q_arr) / sizeof(q_arr[0]);
    int d = 2;

    MultipleArrayRangeIncrementOperations::Solution ob;

    cout << "Original Array:\n";
    ob.printArray(arr, n);

    // modifying the array for multiple queries
    ob.incrementByD(arr, q_arr, n, m, d);

    cout << "\nModified Array:\n";
    ob.printArray(arr, n);

    return 0;

}
