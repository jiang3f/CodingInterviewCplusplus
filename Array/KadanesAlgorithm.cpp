//
// https://practice.geeksforgeeks.org/problems/kadanes-algorithm/0
//


#include "stdafx.h"
#include <iostream>
#include <queue>

#define MIN	-99999
using namespace std;

/*
	Your program took more time than expected.Time Limit Exceeded
	Expected Time Limit < 1.252sec
	Hint : Please optimize your code and submit again.
*/
namespace KadanesAlgorithm_mine
{
	int Run(int arr[], int n)
	{
		queue<int> myQueueOdd, myQueueEven;
		int max = MIN;

		for (int i=0; i < n; i++)
		{
			if (arr[i] > max)	max = arr[i];

			if (i % 2)	myQueueOdd.push(arr[i]);
			else myQueueEven.push(arr[i]);

			if (i % 2)
			{
				while (myQueueEven.size() != 0)
				{
					int v = myQueueEven.front();
					int sum = v + arr[i];
					if (sum > max)	max = sum;
					myQueueOdd.push(sum);
					myQueueEven.pop();
				}
			}
			else
			{
				while (myQueueOdd.size() != 0)
				{
					int v = myQueueOdd.front();
					int sum = v + arr[i];
					if (sum > max)	max = sum;
					myQueueEven.push(sum);
					myQueueOdd.pop();
				}
			}
		}

		return max;

	}
};

namespace KadanesAlgorithm
{
	int Run(int arr[], int n)
	{
		int maxCurrent, max;
		maxCurrent = max = arr[0];

		for (int i = 1; i < n; i++)
		{
			maxCurrent = (arr[i] > (arr[i] + maxCurrent)) ? arr[i] : (arr[i] + maxCurrent);
			if (maxCurrent > max)	max = maxCurrent;
		}
		return max;
	}
};

int KadanesAlgorithm_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		int *arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int ret = KadanesAlgorithm_mine::Run(arr, n);

		cout << ret << endl;

		ret = KadanesAlgorithm::Run(arr, n);

		cout << ret << endl;

	}
	return 0;
}