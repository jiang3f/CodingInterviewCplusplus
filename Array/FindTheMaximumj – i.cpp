//
// https ://www.geeksforgeeks.org/given-an-array-arr-find-the-maximum-j-i-such-that-arrj-arri/
//

#include "stdafx.h"
#include <iostream>
using namespace std;

long min(long a, long b)
{
	return (a < b) ? a : b;
}

long max(long a, long b)
{
	return (a > b) ? a : b;
}

long maxIndexDiff(long arr[], long n)
{
	if (arr[0] <= arr[n - 1]) return n - 1;

	long maxDiff;
	long i, j;

	long *LMin = new long[(sizeof(long) * n)];
	long *RMax = new long[(sizeof(long) * n)];

	LMin[0] = arr[0];
	for (i = 1; i < n; ++i)
		LMin[i] = min(arr[i], LMin[i - 1]);

	RMax[n - 1] = arr[n - 1];
	for (int k = n - 2; k >= 0; --k)
		RMax[k] = max(arr[k], RMax[k + 1]);

	i = 0, j = 0, maxDiff = 0;
	while (j < n && i < n)
	{
		if (LMin[i] <= RMax[j])
		{
			maxDiff = max(maxDiff, j - i);
			j = j + 1;
		}
		else
			i = i + 1;
	}

	return maxDiff;
}

// Driver Code 
int FindTheMaximumj_i_Test()
{
	long test;
	cin >> test;
	while (test--) {

		long num;
		cin >> num;
		long *arr = new long[num];
		for (long i = 0; i < num; i++)	cin >> arr[i];
		int maxDiff = maxIndexDiff(arr, num);
		cout << maxDiff << endl;
	}

	return 0;
}

// This code is contributed by rathbhupendra 

