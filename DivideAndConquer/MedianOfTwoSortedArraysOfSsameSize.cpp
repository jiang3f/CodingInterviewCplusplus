/*
* https://www.geeksforgeeks.org/median-of-two-sorted-arrays/
*/

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace MedianOfTwoSortedArraysOfSsameSize
{
    // time complexity O(n)
    class solution_count_while_Merging
    {
    public:
        float getMedian(int arr1[], int arr2[], int n)
        {
            int i = 0;
            int j = 0;
            int cnt = 0;
            int m1 = 0;
            int m2 = 0;

            for (cnt = 0; cnt < n; cnt++)
            {
                if (i == n)
                {
                    m1 = m2;
                    m2 = arr2[0];
                }
                else if (j == n)
                {
                    m1 = m2;
                    m2 = arr1[0];
                }
                else if (arr1[i] < arr2[j])
                {
                    m1 = m2;
                    m2 = arr1[i];
                    i++;
                }
                else
                {
                    m1 = m2;
                    m2 = arr2[j];
                    j++;
                }
            }
            return ((float)m1 + (float)m2) / 2;
        }
    };

    // time complexity O(logn)
    class solution_comparing_the_medians_of_two_arrays
    {
    private:
        float median(int arr[], int n)
        {
            if (n % 2)    return (arr[n / 2 - 1]);
            else
            {
                return ((float)arr[n / 2 - 1] + (float)arr[n / 2]) / 2;
            }
        }

    public:
        float getMedian(int arr1[], int arr2[], int n)
        {
            if (n == 0) return 0;
            
            if (n == 1) return ((float)arr1[0] + (float)arr2[0]) / 2;

            if (n == 2)
            {
                return ((float)max(arr1[0], arr2[0]) + (float)min(arr1[1], arr2[1])) / 2;
            }

            float m1 = median(arr1, n);
            float m2 = median(arr2, n);

            if (m1 == m2)   return m1;

            else if (m1 < m2)
            {
                if (n % 2 == 0)
                {
                    return getMedian(&arr1[n / 2-1], arr2, n / 2+1);
                }
                else
                {
                    return getMedian(&arr1[n / 2], arr2, n / 2);
                }
            }
            else
            {
                if (n % 2 == 0)
                {
                    return getMedian(&arr2[n / 2 - 1], arr1, n / 2 + 1);
                }
                else
                {
                    return getMedian(&arr2[n / 2], arr1, n / 2);
                }
            }
        }
    };

    // time complexity O(nlogn)
    class solution_taking_union_without_extra_space
    {
    public:
        float getMedian(int arr1[], int arr2[], int n)
        {
            int i = n - 1;
            int j = 0;

            while (i >= 0 && j < n && arr1[i] > arr2[j])
            {
                swap(arr1[i--], arr2[j++]);
            }
            sort(arr1, arr1+n);
            sort(arr2, arr2+n);

            return ((float)arr1[n - 1] + (float)arr2[0]) / 2;
        }
    };
};


int MedianOfTwoSortedArraysOfSsameSize_Test ()
{
    int ar1[] = { 1, 12, 15, 26, 38 };
    int ar2[] = { 2, 13, 17, 30, 45 };
        
    int n1 = sizeof(ar1) / sizeof(ar1[0]);
    int n2 = sizeof(ar2) / sizeof(ar2[0]);
    if (n1 == n2)
    {
        MedianOfTwoSortedArraysOfSsameSize::solution_count_while_Merging ob;
        cout << "Median is " << ob.getMedian(ar1, ar2, n1) << endl;
    }
    else
        cout << "Doesn't work for arrays of unequal size" << endl;
    return 0;
}