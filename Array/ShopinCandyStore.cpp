//
// https://practice.geeksforgeeks.org/problems/shop-in-candy-store/0
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;
namespace ShopinCandyStore
{
	int MinCost (int n, int k, int arr[])
	{
		int min = 0;
		int p = 0;
		sort(arr, arr + n);

		for (int i = 0; i < n - p; i++)
		{
			p += k;
			min += arr[i];
		}
		return min;

	}

	int MaxCost(int n, int k, int arr[])
	{
		int max = 0;
		int p = 0;
		sort(arr, arr + n, greater<int>());
		for (int i = 0; i < n - p; i++)
		{
			max += arr[i];
			p += k;
		}
		return max;
	}
};

namespace ShopinCandyStore_solution1
{
	//
	// https://ide.geeksforgeeks.org/QVVSdnXggC
	// 

	void Run(int n, int k, int arr[])
	{
		int mn = 0, mx = 0;
		int p = 0, x = 0;
		sort(arr, arr + n);
		// for minimum
		for (int i = 0; i<n - p; i++)
		{
			mn += arr[i];
			p += k;
		}
		x = 0;
		sort(arr, arr + n, greater<int>());
		for (int j = 0; j<n - x; j++)
		{
			mx += arr[j];
			x += k;
		}
		cout << mn << " " << mx << endl;
	}
};

int ShopinCandyStore_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		int k;
		cin >> k;

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int min = ShopinCandyStore::MinCost(n, k, arr);
		int max = ShopinCandyStore::MaxCost(n, k, arr);

		cout << min << " " << max << endl;

		ShopinCandyStore_solution1::Run(n, k, arr );
	}
	return 0;
			
}
