//
// https://www.geeksforgeeks.org/counting-inversions/
//
#include "stdafx.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

namespace MergeSortArray
{

	void Merge(long *leftArr, long leftLen, long * rightArr, long rightLen, long *out)
	{
		long i = 0;
		long j = 0;
		long size = 0;
		while (i < leftLen && j < rightLen)
		{
			if (leftArr[i] < rightArr[j])
			{
				out[size++] = leftArr[i++];
			}
			else
			{
				out[size++] = rightArr[j++];
			}
		}

		while (i < leftLen)	out[size++] = leftArr[i++];

		while (j < rightLen) out[size++] = rightArr[j++];

	}

	void MergeSort(long *arr, long len)
	{
		if (len < 2)
		{
			return;
		}

		long mid = len / 2;

		long *leftArr = new long[mid];
		for (long i = 0; i < mid; i++)	leftArr[i] = arr[i];
		MergeSort(leftArr, mid);

		long *rightArr = new long[len - mid];
		for (long i = 0; i < len - mid; i++)	rightArr[i] = arr[mid + i];
		MergeSort(rightArr, len - mid);

		Merge(leftArr, mid, rightArr, len - mid, arr);
	}
};

//
// 1 
// 5
// 1, 20, 6, 4, 5
int MergeSortArray_Test()
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
		
		MergeSortArray::MergeSort(arr, n);
	}
	return 0;
}  // } Driver Code Ends

