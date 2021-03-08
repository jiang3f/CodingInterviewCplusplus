//
// https://practice.geeksforgeeks.org/problems/k-th-element-of-two-sorted-array1317/1
// https://www.geeksforgeeks.org/k-th-element-two-sorted-arrays/
//

/*
Expected Time Complexity: O(Log(N) + Log(M))
Expected Auxiliary Space: O(Log (N))


Constraints:
1 <= N, M <= 106
1 <= arr1i, arr2i <= 106
1 <= K <= N+M
*/

#include "stdafx.h"
#include <iostream>


using namespace std;

namespace KthElementOfTwoSortedArrays
{
	class Solution {
	public:
		int kthElement(int arr1[], int arr2[], int n, int m, int k)
		{
			int i = 0;
			int j = 0;
			
			int id = 0;
			int current = 0;

			while (i < n && j < m)
			{

				if (arr1[i] < arr2[j])
				{
					current = arr1[i];
					i++;
				}
				else
				{
					current = arr2[j];
					j++;
				}
				id++;

				//cout << current << " ";

				if (id == k)	break;
			}
			
			if (id < k)
			{
				while (i < n && id < k)
				{
					current = arr1[i];
					id++;
					i++;
					//cout << current << " ";
				}

				while (j < m && id < k)
				{
					current = arr2[j];
					j++;
					id++;
					//cout << current << " ";
				}

			}
			//cout << endl;

			return current;
		}
	};

};

namespace KthElementOfTwoSortedArrays_Dp
{
	class Solution {
	private:
		int kthSub(int* arr1, int* arr2, int* end1, int* end2, int k)
		{
			if (arr1 == end1)
			{
				return arr2[k];
			}
			else if (arr2 == end2)
			{
				return arr1[k];
			}

			int mid1 = (end1 - arr1) / 2;
			int mid2 = (end2 - arr2) / 2;

			if (mid1 + mid2 > k)
			{
				if (arr1[mid1] > arr2[mid2])
				{
					// exclude arr1[mid1+1]...arr1[n-1]
					return kthSub(arr1, arr2, arr1 + mid1, end2, k);
				}
				else
				{
					return kthSub(arr1, arr2, end1, arr2 + mid2, k);
				}
			}
			else
			{
				if (arr1[mid1] < arr2[mid2])
				{
					// exclude arr1[0] ... arr1[mid1]
					return kthSub(arr1 + mid1 + 1, arr2, end1, end2, k - mid1-1);
				}
				else
				{
					return kthSub(arr1, arr2 + mid2 + 1, end1, end2, k - mid2-1	);
				}
			}
		}

	public:
		int kthElement(int arr1[], int arr2[], int n, int m, int k)
		{
			return kthSub(arr1, arr2, arr1 + n, arr2 + m, k - 1);
		}
	};
};

int KthElementOfTwoSortedArrays_Test()
{
	/*
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;

		int *arr1, *arr2;
		arr1 = new int[n];
		arr2 = new int[m];

		for (int i = 0; i < n; i++)
			cin >> arr1[i];
		for (int i = 0; i < m; i++)
			cin >> arr2[i];

		KthElementOfTwoSortedArrays::Solution ob;
		cout << ob.kthElement(arr1, arr2, n, m, k) << endl;
	}
	*/

	int arr1[] = { 24, 50, 92, 95 };
	int arr2[] = { 1,2,6,6,8,8,11,11,12,12,13,13,14,15,16,16,17,17,17,19,21,21,22,22,24,24,25,27,29,32,33,34,35,35,35,36,38,40,41,43,44,45,46,46,47,48,50,50,50,54,54,54,54,54,57,58,60,60,61,62,67,68,69,73,73,74,75,76,78,78,79,80,81,82,82,83,83,85,86,87,87,88,88,90,91,91,92,92,92,93,95,95,95,96,97,97,98};

	KthElementOfTwoSortedArrays_Dp::Solution ob;
	cout << ob.kthElement(arr1, arr2, 4, 97, 98) << endl;

	return 0;

}

