//
// https://practice.geeksforgeeks.org/problems/minimize-the-heights/0/
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;
namespace MinimizeTheHeights
{
	int Run(int arr[], int n, int k)
	{
		if (n == 1)	return 0;

		sort(arr, arr + n);

		int minMax = 0;

		for (int i = 0; i < n - 1; i++)
		{
			int maxHeight = arr[i] - arr[0];
			if (maxHeight < (arr[i] - arr[i + 1] + 2 * k))
			{
				maxHeight = arr[i] - arr[i + 1] + 2 * k;
			}
			if (maxHeight < (arr[n - 1] - arr[i + 1]))
			{
				maxHeight = arr[n - 1] - arr[i + 1];
			}
			if (maxHeight < (arr[n - 1] - 2 * k - arr[0]))
			{
				maxHeight = arr[n - 1] - 2 * k - arr[0];
			}
			if (i == 0)	minMax = maxHeight;

			if (maxHeight < minMax)	minMax = maxHeight;
		}

		if (minMax > (arr[n-1] - arr[0]))	minMax = arr[n-1] - arr[0];

		return minMax;
	}
};

int MinimizeTheHeights_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int k, n;
		cin >> k >> n;

		int* arr = new int[n];

		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		
		int ret = MinimizeTheHeights::Run(arr, n, k);

		cout << ret << endl;

	}
	return 0;
}

