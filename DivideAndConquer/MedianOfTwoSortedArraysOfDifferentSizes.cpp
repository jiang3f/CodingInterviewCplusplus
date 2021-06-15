/*
*  https://www.geeksforgeeks.org/median-of-two-sorted-arrays-of-different-sizes/
*/


#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

namespace MedianOfTwoSortedArraysOfDifferentSizes
{
	// Calculate the median of both the arrays and discard one half of each 
	// O(logn)

	class Solution_comparing_the_medians_of_two_arrays {
	protected:
		double GetMedian(int a, int b)
		{
			return ((double)a + (double)b) / 2;
		}

		// a0 < a1, b0 < b1;
		double GetMedian(int a0, int a1, int b0, int b1)
		{
			return (double)(max(a0, b0) + min(a1, b1)) / 2;
		}

		// b0 < b1
		int GetMedian(int a0, int b0, int b1)
		{
			if (a0 < b0)	return b0;
			else if (a0 > b1)	return b1;
			else return a0;
		}

		double GetMedian(int arr[], int n)
		{
			if (n == 0)	return 0;

			if (n % 2)
			{
				return (double)arr[n / 2];
			}
			else
			{
				return ((double)arr[n / 2 - 1] + (double)arr[n / 2]) / 2;
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
				len = n / 2 + 1;
			}
			return arr;
		}

		int* GetSecondHalf(int arr[], int n, int& len)
		{
			if (n % 2)
			{
				len = n / 2 + 1;
				return &arr[n / 2];
			}
			else
			{
				len = n / 2 + 1;
				return &arr[n / 2 - 1];
			}
		}

		double FindMedian_sub(int arr1[], int n, int arr2[], int m)
		{
			if (n == 1)
			{
				if (m == 1)
				{
					return GetMedian(arr1[0], arr2[0]);
				}
				else if (m == 2)
				{
					return (double)GetMedian(arr1[0], arr2[0], arr2[1]);
				}
				else
				{
					if (m % 2)
					{
						if (arr1[0] > arr2[m / 2 + 1])
						{
							return GetMedian(arr2[m / 2], arr2[m / 2 + 1]);
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
							return (double)arr2[m / 2];
						}
						else if (arr1[0] < arr2[m / 2 - 1])
						{
							return (double)arr2[m / 2 - 1];
						}
						else
						{
							return (double)arr1[0];
						}

					}
				}
			}
			else if (n == 2)
			{
				if (m == 1)
				{
					return (double)GetMedian(arr2[0], arr1[0], arr1[1]);
				}
				else if (m == 2)
				{
					return GetMedian(arr1[0], arr1[1], arr2[0], arr2[1]);
				}
				else
				{
					if (m % 2)
					{
						if (arr1[0] > arr2[m / 2 + 1])	return (double)arr2[m / 2 + 1];
						else if (arr1[1] < arr2[m / 2 - 1])	return (double)arr2[m / 2 - 1];
						else 						return (double)GetMedian(arr2[m / 2], arr1[0], arr1[1]);
					}
					else
					{
						if (arr1[0] > arr2[m / 2 +1])	return (double)GetMedian(arr2[m / 2], arr2[m / 2 + 1]);
						else if (arr1[1] < arr2[m / 2 - 2]) return (double)GetMedian(arr2[m / 2 - 2], arr2[m / 2 - 1]);
						return GetMedian(arr1[0], arr1[1], arr2[m / 2 - 1], arr2[m / 2]);
					}
				}
			}
			else
			{
				int index1 = (n - 1) / 2;
				int index2 = (m - 1) / 2;
				
				int m1 = arr1[index1];
				int m2 = arr2[index2];

				if (m1 <= m2)
				{
					return FindMedian_sub(&arr1[index1], n - index1, arr2, m - index1);
				}
				else
				{
					return FindMedian_sub(arr1, n - index1, &arr2[index1], m- index1);
				}
			}
			return -1;
		}

	public:
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
		{
			int n = nums1.size();
			int m = nums2.size();

			if (n == 0 && m == 0) return 0;

			else if (n == 0)    return GetMedian(&nums2[0], m);

			else if (m == 0)    return GetMedian(&nums1[0], n);

			else if (n < m)  return FindMedian_sub(&nums1[0], n, &nums2[0], m);

			else return FindMedian_sub(&nums2[0], m, &nums1[0], n);

		}

		double FindMedian(int arr1[], int n, int arr2[], int m)
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

	class Solution_demo
	{
	protected:
		// A utility function to find median of two integers
		float MO2(int a, int b)
		{
			return (a + b) / 2.0;
		}

		// A utility function to find median of three integers
		float MO3(int a, int b, int c)
		{
			return a + b + c - max(a, max(b, c))
				- min(a, min(b, c));
		}

		// A utility function to find a median of four integers
		float MO4(int a, int b, int c, int d)
		{
			int Max = max(a, max(b, max(c, d)));
			int Min = min(a, min(b, min(c, d)));
			return (a + b + c + d - Max - Min) / 2.0;
		}

		// Utility function to find median of single array
		float medianSingle(int arr[], int n)
		{
			if (n == 0)
				return -1;
			if (n % 2 == 0)
				return (double)(arr[n / 2] + arr[n / 2 - 1]) / 2;
			return arr[n / 2];
		}

		// This function assumes that N is smaller than or equal to M
		// This function returns -1 if both arrays are empty
		float findMedianUtil(int A[], int N, int B[], int M)
		{
			// If smaller array is empty, return median from second array
			if (N == 0)
				return medianSingle(B, M);

			// If the smaller array has only one element
			if (N == 1)
			{
				// Case 1: If the larger array also has one element,
				// simply call MO2()
				if (M == 1)
					return MO2(A[0], B[0]);

				// Case 2: If the larger array has odd number of elements,
				// then consider the middle 3 elements of larger array and
				// the only element of smaller array. Take few examples
				// like following
				// A = {9}, B[] = {5, 8, 10, 20, 30} and
				// A[] = {1}, B[] = {5, 8, 10, 20, 30}
				if (M & 1)
					return MO2(B[M / 2], MO3(A[0], B[M / 2 - 1], B[M / 2 + 1]));

				// Case 3: If the larger array has even number of element,
				// then median will be one of the following 3 elements
				// ... The middle two elements of larger array
				// ... The only element of smaller array
				return MO3(B[M / 2], B[M / 2 - 1], A[0]);
			}

			// If the smaller array has two elements
			else if (N == 2)
			{
				// Case 4: If the larger array also has two elements,
				// simply call MO4()
				if (M == 2)
					return MO4(A[0], A[1], B[0], B[1]);

				// Case 5: If the larger array has odd number of elements,
				// then median will be one of the following 3 elements
				// 1. Middle element of larger array
				// 2. Max of first element of smaller array and element
				// just before the middle in bigger array
				// 3. Min of second element of smaller array and element
				// just after the middle in bigger array
				if (M & 1)
					return MO3(B[M / 2],
						max(A[0], B[M / 2 - 1]),
						min(A[1], B[M / 2 + 1])
					);

				// Case 6: If the larger array has even number of elements,
				// then median will be one of the following 4 elements
				// 1) & 2) The middle two elements of larger array
				// 3) Max of first element of smaller array and element
				// just before the first middle element in bigger array
				// 4. Min of second element of smaller array and element
				// just after the second middle in bigger array
				return MO4(B[M / 2],
					B[M / 2 - 1],
					max(A[0], B[M / 2 - 2]),
					min(A[1], B[M / 2 + 1])
				);
			}

			int idxA = (N - 1) / 2;
			int idxB = (M - 1) / 2;

			/* if A[idxA] <= B[idxB], then median must exist in
				A[idxA....] and B[....idxB] */
			if (A[idxA] <= B[idxB])
				return findMedianUtil(A + idxA, N / 2 + 1, B, M - idxA);

			/* if A[idxA] > B[idxB], then median must exist in
			A[...idxA] and B[idxB....] */
			return findMedianUtil(A, N / 2 + 1, B + idxA, M - idxA);
		}
	public:
		// A wrapper function around findMedianUtil(). This function
		// makes sure that smaller array is passed as first argument
		// to findMedianUtil
		float findMedian(int A[], int N, int B[], int M)
		{
			if (N > M)
				return findMedianUtil(B, M, A, N);

			return findMedianUtil(A, N, B, M);
		}

	};
};




int MedianOfTwoSortedArraysOfDifferentSizes_Test()
{
	//int A[] = { 900 };
	//int B[] = { 5, 8, 10, 20 };
	//int A[] = { -5, 3, 6, 12, 15 };
	//int B[] = { -12, -10, -6, -3, 4, 10 };
	//int A[] = { 2, 3, 5, 8 };
	//int B[] = { 10, 12, 14, 16, 18, 20 };
	int A[] = { 1, 2, 6, 7};
	int B[] = { 3, 4, 5, 6};

	int N = sizeof(A) / sizeof(A[0]);
	int M = sizeof(B) / sizeof(B[0]);

	
	MedianOfTwoSortedArraysOfDifferentSizes::Solution_comparing_the_medians_of_two_arrays ob;

	printf("%f", ob.FindMedian(A, N, B, M));
	
	//MedianOfTwoSortedArraysOfDifferentSizes::Solution_demo ob;

	//cout << ob.findMedian(A, N, B, M) << endl;

	/*
	vector<int> A = { 1, 2, 3 };
	vector<int> B = { 4, 5, 6, 7,8 };

	MedianOfTwoSortedArraysOfDifferentSizes::Solution_comparing_the_medians_of_two_arrays ob;
	cout << ob.findMedianSortedArrays(A, B) << endl;
	*/
	
	return 0;

}