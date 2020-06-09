//
// https://practice.geeksforgeeks.org/problems/coin-piles/0/
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

namespace CoinPiles
{

	#define MAX_VALUE	9999999

	int Run(int arr[], int n, int k)
	{

		sort(arr, arr + n);

		int ret = MAX_VALUE;

		for (int i = 0; i < n; i++)
		{
			int total = 0;

			for (int j = 0; j < i; j++)	total += arr[j];

			int max = arr[i] + k;

			for (int j = n - 1; j > i; j--)
			{
				if (arr[j] > max)	total += (arr[j] - max);
			}

			if (ret > total)	ret = total;
//			else break;

		}
		return ret;
	}
};

int CoinPiles_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int n, k;
		cin >> n >> k;

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int ret = CoinPiles::Run(arr, n, k);

		cout << ret << endl;
	}
	return 0;
}

