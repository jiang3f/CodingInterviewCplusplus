//
// https://practice.geeksforgeeks.org/problems/-minimum-number-of-coins/0/
//

#include "stdafx.h"
#include <iostream>

using namespace std;

namespace MinimumNumberOfCoins
{
	int Run(int v)
	{
		int coins[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000 };

		int n = sizeof(coins) / sizeof(coins[0]);

		
		for (int i = n - 1; i >= 0; i--)
		{
			int numOfCoins = v / coins[i];

			for (int j = 0; j < numOfCoins; j++)	cout << coins[i] << " ";

			v = v % coins[i];
		}
		
		cout << endl;

		return 0;
	}
};

int MinimumNumberOfCoins_Test()
{
	int test;
	cin >> test;

	while (test--)
	{
		int v;

		cin >> v;

		MinimumNumberOfCoins::Run(v);
	}
	return 0;
}