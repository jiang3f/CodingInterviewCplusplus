/*
* https://www.geeksforgeeks.org/sqrt-square-root-decomposition-technique-set-1-introduction/
*/


/*
* 
Problem :
Given an array of n elements. We need to answer q
queries telling the sum of elements in range l to
r in the array. Also the array is not static i.e
the values are changed via some point update query.

Range Sum Queries are of form : Q l r ,
where l is the starting index r is the ending
index

Point update Query is of form : U idx val,
where idx is the index to update val is the
updated value*/

// 

#include "stdafx.h"
#include <iostream>
using namespace std;

namespace QueriesTheSumOfElementsInRangeLeftToRight
{
    const int MAX_ELEMENTS = 10000;
    const int MAX_SQT_ELEMENTS = 100;

    class Solution
    {
        int *arr;
        int srd[MAX_SQT_ELEMENTS];
        int sqtCount;

    public:
        void preprocess(int arr1[], int n)
        {
            sqtCount = sqrt(n);

            arr = arr1;

            for (int i = 0; i < sqtCount; i++)
            {
                srd[i] = 0;
            }

            for (int i = 0; i < n; i++)
            {
                srd[i / sqtCount] += arr[i];
            }

            cout << "srd = {";

            for (int i = 0; i < sqtCount; i++)
            {
                cout << srd[i] << ",";
            }

            cout << "}" << endl;

        };

        int query(int left, int right)
        {

            int sum = 0;

            while (left < right && (left % sqtCount) != 0)
            {
                sum += arr[left];
                left++;
            }

            int i = 0;
            for (i = (left / sqtCount); i < ((right + 1) / sqtCount) && left < right; i++)
            {
                sum += srd[i];
                left += sqtCount;
            }

            while (left <= right)
            {
                sum += arr[left++];
            }

            return sum;
        }

        void update(int index, int value)
        {
            srd[index / sqtCount] += (value - arr[index]);
            arr[index] = value;
        }
    };
};

int QueriesTheSumOfElementsInRangeLeftToRight_Test()
{
    // We have used separate array for input because
    // the purpose of this code is to explain SQRT
    // decomposition in competitive programming where
    // we have multiple inputs.
    int input[] = { 1, 5, 2, 4, 6, 1, 3, 5, 7, 10 };
    int n = sizeof(input) / sizeof(input[0]);

    QueriesTheSumOfElementsInRangeLeftToRight::Solution ob;
    
    ob.preprocess(input, n);

    //cout << "query(3,8) : " << ob.query(3, 8) << endl;
    //cout << "query(1,6) : " << ob.query(1, 6) << endl;
    ob.update(8, 0);
    cout << "query(8,8) : " << ob.query(8, 8) << endl;
    return 0;
}