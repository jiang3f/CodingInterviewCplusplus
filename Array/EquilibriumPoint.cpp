//
// https://practice.geeksforgeeks.org/problems/equilibrium-point/0/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace EquilibriumPoint
{
	int Run(int arr[], int n)
	{
		if (n == 1)	return 1;
		else if (n == 2)	return -1;
		else
		{
			int sumBefore = arr[0];
			int sumAfter = arr[n - 1];

			int before = 0;
			int after = n - 1;

			while (after > before + 2)
			{
				if (sumAfter > sumBefore)
				{
					before++;
					sumBefore += arr[before];
				}
				else
				{
					after--;	
					sumAfter += arr[after];
				}
			}

			if (sumAfter == sumBefore)
			{
				return after;
			}
			else
			{
				return -1;
			}

		}
	}
};

int EquilibriumPoint_Test()
{
	int test;
	cin >> test;
	while (test--)
	{
		int n;
		cin >> n;

		int * arr = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}

		int ret = EquilibriumPoint::Run(arr, n);

		cout << ret << endl;
	}

	return 0;

}
