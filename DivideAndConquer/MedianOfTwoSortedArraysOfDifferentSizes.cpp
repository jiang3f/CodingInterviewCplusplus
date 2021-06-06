/*
*  https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
*/


#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace MedianOfTwoSortedArraysOfDifferentSizes
{
	// Calculate the median of both the arrays and discard one half of each 
	// O(logn)
	class Solution_comparing_the_medians_of_two_arrays
	{
	private:
		float GetMedian(int a, int b)
		{
			return ((float)a + (float)b) / 2;
		}

		// a0 < a1, b0 < b1;
		float GetMedian(int a0, int a1, int b0, int b1)
		{
			return (float)(max(a0, b0) + min(a1, b1)) / 2;
		}
		
		// b0 < b1
		int GetMedian(int a0, int b0, int b1)
		{
			if (a0 < b0)	return b0;
			else if (a0 > b1)	return b1;
			else return a0;
		}

		int GetMedian(int arr[], int n)
		{
			if (n == 0)	return -1;

			if (n % 2)
			{
				return (arr[n / 2 - 1] + arr[n / 2]) / 2;
			}
			else
			{
				return arr[n / 2];
			}
		}

		int* GetFirstHalf(int arr[], int n, int& len)
		{
			if (n % 2)
			{
				len = n / 2 + 1;
			}
			else
			{
				len = n / 2;
			}
			return arr;
		}

		int *GetSecondHalf (int arr[], int n, int& len)
		{
			if (n % 2)
			{
				len = n / 2 + 1;
			}
			else
			{
				len = n / 2;
			}
			return &arr[n / 2];
		}
		float FindMedian_sub(int arr1[], int n, int arr2[], int m)
		{
			if (n == 1)
			{
				if (m == 1)
				{
					return GetMedian(arr1[0], arr2[0]);
				}
				else if (m == 2)
				{
					return (float)GetMedian(arr1[0], arr2[0], arr2[1]);
				}
				else
				{
					if (m % 2)
					{
						if (arr1[0] > arr2[m / 2 + 1])
						{
							return GetMedian (arr2[m / 2], arr2[m/2+1]);
						}
						else if (arr1[0] < arr2[m / 2 - 1])
						{
							return GetMedian(arr2[m / 2 - 1], arr2[m / 2]);
						}
						else 
						{
							return GetMedian(arr2[m / 2], arr1[0]);
						}
					}
					else
					{
						if (arr1[0] > arr2[m / 2])
						{
							return (float)arr2[m/2];
						}
						else if (arr1[0] < arr2[m / 2-1])
						{
							return (float)arr2[m / 2 -1];
						}
						else
						{
							return (float)arr1[0];
						}

					}
				}
			}
			else if (n == 2)
			{
				if (m == 1)
				{
					return (float)GetMedian(arr2[0], arr1[0], arr1[1]);
				}
				else if (m == 2)
				{
					return GetMedian(arr1[0], arr1[1], arr2[0], arr2[1]);
				}
			}
			else
			{
				int m1 = GetMedian(arr1, n);
				int m2 = GetMedian(arr2, m);

				if (m1 < m2)
				{
					int l1, l2;
					int* p1 = GetSecondHalf(arr1, n, l1);
					int* p2 = GetFirstHalf(arr2, m, l2);

					return FindMedian_sub(p1, l1, p2, l2);
				}
				else
				{
					int l1, l2;
					int* p1 = GetFirstHalf(arr1, n, l1);
					int* p2 = GetSecondHalf(arr2, m, l2);
					return FindMedian_sub(p1, l1, p2, l2);
				}
			}
			return -1;
		}
	public:
		float FindMedian(int arr1[], int n, int arr2[], int m)
		{
			if (n == 0 || m == 0)	return -1;

			if (n <= m)
			{
				return FindMedian_sub(arr1, n, arr2, m);
			}
			else
			{
				return FindMedian_sub(arr2, m, arr1, n);
			}
		}
	};
};

int MedianOfTwoSortedArraysOfDifferentSizes_Test()
{
	int A[] = { 900 };
	int B[] = { 5, 8, 10, 20 };

	int N = sizeof(A) / sizeof(A[0]);
	int M = sizeof(B) / sizeof(B[0]);

	MedianOfTwoSortedArraysOfDifferentSizes::Solution_comparing_the_medians_of_two_arrays ob;

	printf("%f", ob.FindMedian(A, N, B, M));
	return 0;

}