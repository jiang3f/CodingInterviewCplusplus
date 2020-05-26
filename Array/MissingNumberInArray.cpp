//
// https://practice.geeksforgeeks.org/problems/missing-number-in-array/0/
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace MissingNumberInArray
{
	int Run (int arr[], int n)
	{
		sort(arr, arr + n - 1);

		int v = 1;
		for (int i = 0; i < n - 1; i++)
		{
			if (arr[i] != v)	break;
			v++;
		}

		return v;
	}

};

int MissingNumberInArray_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;
		int *arr = new int[n - 1];

		for (int i = 0; i < n - 1; i++)
		{
			cin >> arr[i];
		}

		int ret = MissingNumberInArray::Run(arr, n);

		cout << ret << endl;
	}

	return 0;
}