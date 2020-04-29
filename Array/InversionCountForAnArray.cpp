//
// https://www.geeksforgeeks.org/counting-inversions/
//

#include "stdafx.h"
#include <iostream>
using namespace std;

// Driver Code 
//
// 1
// 4
// 8, 4, 2, 1

//
//
//
// Time Complexity : O(n ^ 2), Two nested loops are needed to traverse the array from start to end so the Time complexity is O(n ^ 2)
// Space Compelxity : O(1), No extra space is required.

void InversionCountForAnArray_method1(int *arr, int len)
{
	int count = 0;

	for (int i = len - 1; i > 0; i--)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int v = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = v;
				count++;
			}
		}
	}
	for (int i = 0; i < len; i++)	cout << arr[i] << " ";
	cout << endl;

	cout << count << endl;

}

void InversionCountForAnArray_method2(int *arr, int len)
{

}

int InversionCountForAnArray_Test()
{
	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;
		int *arr = new int[n];
		for (int i = 0; i<n; i++)
		{
			cin >> arr[i];
		}
		InversionCountForAnArray_method1(arr, n);

	}
	return 0;
}

// This code is contributed by rathbhupendra 

