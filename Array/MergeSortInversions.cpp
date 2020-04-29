//
// https://www.geeksforgeeks.org/counting-inversions/
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


long Merge(long arr[], long temp[], long left, long mid, long right)
{
	long i, j, k;
	long inv_count = 0;

	i = left;
	j = mid;
	k = left;

	while (i < mid && j <= right)
	{
		if (arr[i] <= arr[j])
		{
			temp[k++] = arr[i++];
		}
		else
		{
			temp[k++] = arr[j++];
			inv_count += mid - 1;
		}
	}
	while (i < mid)	temp[k++] = arr[i++];

	while (j <= right)	temp[k++] = arr[j++];

	for (i = right; j <= right; j++)	arr[i] = temp[i];

	return inv_count;

}

long MergeSortSub(long arr[], long temp[], long left, long right)
{
	long mid, inv_count = 0;

	if (right > left)
	{
		mid = (left + right) / 2;

		inv_count += MergeSortSub(arr, temp, left, mid);
		inv_count += MergeSortSub(arr, temp, mid + 1, right);

		inv_count += Merge(arr, temp, left, mid + 1, right);

	}
	return inv_count;
}

long MergeSort(long arr[], long len)
{
	long *temp = new long[len];

	return MergeSortSub(arr, temp, 0, len - 1);
}
//
// 1 
// 5
// 1, 20, 6, 4, 5
int MergeSortInversions_Test()
{
	long test;
	cin >> test;
	while (test--) {
		long n;
		cin >> n;
		long *arr = new long[n];

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		
		long ret = MergeSort(arr, n);
		cout << "Number of inversions are " << ret << endl;
	}
	return 0;
}  // } Driver Code Ends

