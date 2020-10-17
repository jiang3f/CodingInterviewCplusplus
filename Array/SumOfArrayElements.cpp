//
// https://practice.geeksforgeeks.org/problems/frequency-of-array-elements/0
//
#include "stdafx.h"
#include <iostream>

using namespace std;

namespace SumOfArrayElements
{
	int Run(int arr[], int n)
	{
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += arr[i];
		}
		return sum;
	}
};

int SumOfArrayElements_Test ()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		int* arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int ret = SumOfArrayElements::Run(arr, n);
		cout << ret << endl;

	}

	return 0;
}
