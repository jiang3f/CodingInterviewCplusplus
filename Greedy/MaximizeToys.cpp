//
// https://practice.geeksforgeeks.org/problems/maximize-toys/0/
//

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

namespace MaximizeToys
{
	int Run(int arr[], int n, int k)
	{
		sort(arr, arr + n);

		int sum = 0;
		int i = 0;
		for (i = 0; i < n; i++)
		{
			sum += arr[i];

			if (sum > k)	break;
		}

		return i;
	}
};

namespace MaximizeToys_Queue
{

	int Run(int a[], int n, int k)
	{
		int i;

		priority_queue<int, vector<int>, greater<int> > p;

		for (i = 0; i<n; i++)
		{
			p.push(a[i]);
		}

		int count = 0, x = 0;
		for (i = 0; i<n; i++)
		{
			x = p.top();
			p.pop();
			k = k - x;
			if (k<0)
			{
				break;
			}
			else
			{
				count++;
			}
		}

		return count;
	}
}
int MaximizeToys_Test()
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

		int ret = MaximizeToys_Queue::Run(arr, n, k);

		cout << ret << endl;
	}

	return 0;
}